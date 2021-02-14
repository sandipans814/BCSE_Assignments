import asyncio
from asyncio import Queue
import random
from frame import Frame

class Channel():
    def __init__(self):
        self.senders = []
        self.receivers = []

    async def connect(self, node) -> None:
        if isinstance(node, Sender) and node not in self.senders:
            self.senders.append(node)
            print(node.name, "   :\thas joined the channel.")
        elif isinstance(node, Receiver) and node not in self.receivers:
            self.receivers.append(node)
            print(node.name, " :\thas joined the channel.")

    async def transmit(self, node):
        if node not in self.senders:
            print("Channel      :\tPlease join the channel first!")
        else:
            await asyncio.sleep(random.randint(2, 3)) # ! Changed
            f = await node.out_queue.get()
            x = random.randrange(-1, 3)
            # print("Random selector : ", x)
            if(x <= 0):
                f = await node.out_queue.get()
            r = list(filter(lambda x: x.name == f.destination_address, self.receivers))[0]
            # if not r.in_queue.empty():
            #     del r.in_queue
            r.in_queue = asyncio.Queue()
            await r.in_queue.put(f)
            print("Channel     :\tsent to", r.name, "!")
            await asyncio.sleep(random.randint(1, 3)) # ! Changed
            await r.recv()
            await asyncio.sleep(random.randint(2, 3)) # ? Added
            # print("Sanity Check!") # ? Added
            ack = await r.out_queue.get()
            await asyncio.sleep(random.randint(1, 3)) # ? Added
            # print("Sanity Check! 2") # ? Added
            await node.in_queue.put(ack)

class Sender():
    def __init__(self, name, window_size):
        self.name = name
        self.frames = None
        self.window_size = window_size
        self.window_start = 0
        self.window_end = self.window_start + self.window_size - 1
        self.in_queue = Queue()
        self.out_queue = Queue()

    def set_sequence_no(self, frames):
        for i in range(0, len(frames)):
            frames[i].payload["seq_no"] = i % self.window_size
        return frames

    async def send(self, frames: list, channel: 'Channel'):
        self.frames = self.set_sequence_no(frames)
        current_frames = self.frames[self.window_start: self.window_size]
        print(list(map(lambda x: x.payload['seq_no'], current_frames)))
        await channel.connect(self)
        print(self.name, "   :\t sending first batch of frames, window size:", self.window_size)
        for i in current_frames:
            await self.out_queue.put(i)
        while self.window_start <= self.window_end:
            while True:
                try:
                    await asyncio.wait_for(channel.transmit(self), timeout = 12)
                    val = await asyncio.wait_for(self.in_queue.get(), timeout = 10)
                    val = int(str(val), 2) % self.window_size
                    # print("val", val, 'abc', current_frames[0].payload['seq_no'] + 1)
                    if val == ((current_frames[0].payload['seq_no'] + 1) % self.window_size):
                        print(self.name, "   :\t ACK for seq_no", val, "received successfully!")
                        del current_frames[0]
                        self.window_start += 1
                        if self.window_end < len(frames) - 1:
                            self.window_end += 1
                            current_frames.append(frames[self.window_end])
                        # print(self.window_start, self.window_end)
                        print(list(map(lambda x: x.payload['seq_no'], current_frames)))
                        if current_frames:
                            print(self.name, "   :\t Frame with seq_no", current_frames[-1].payload['seq_no'], "sent in the window!")
                            await self.out_queue.put(current_frames[-1])
                        break
                    else:
                        print(self.name, "   :\tThere seems to be an error, retransmitting the current window")
                        await asyncio.sleep(1)
                        del self.out_queue
                        self.out_queue = Queue()
                        for i in current_frames:
                            await self.out_queue.put(i)
                except asyncio.TimeoutError as e:
                    print(self.name, "   :\tTimed Out!", e)
                    await asyncio.sleep(1)
                    print(self.name, "   :\tRetransmitting the current window.")
                    del self.out_queue 
                    # ! Changed
                    self.out_queue = Queue()
                    # ! Changed
                    for i in current_frames:
                        await self.out_queue.put(i)
                await asyncio.sleep(3)
        await asyncio.sleep(1)
        print(self.name, "   :\tTransmission was successful!")

class Receiver():
    def __init__(self, name):
        self.name = name
        self.in_queue = Queue()
        self.out_queue = Queue()
        self.buffer = []

    async def conn(self, channel: 'Channel'):
        await asyncio.sleep(1)
        await channel.connect(self)

    async def recv(self):
        val = await asyncio.wait_for(self.in_queue.get(), timeout = 5)
        # print(val.payload["seq_no"])
        if not self.buffer: 
            if val.payload['seq_no'] == 0:
                self.buffer.append(val)
            else:
                return
            print(self.name, " :\thas received frame with seq no.", val.payload['seq_no'], "from", val.source_address)
        elif self.buffer[-1].payload['seq_no'] == val.payload['seq_no']:
            print(self.name, " :\thas already received this frame, hence discarded.")
        elif (self.buffer[-1].payload['seq_no'] + 1) % 4 != val.payload['seq_no'] :
            print(self.name, " :\tLost frame, retransmission required.")
            return
        else:
            print(self.name, " :\thas received frame with seq no.", val.payload['seq_no'], "from", val.source_address)
            self.buffer.append(val)
        ack = Frame()
        ack.setData(f"{bin(self.buffer[-1].payload['seq_no'] + 1)[2:]}")
        ack.source_address = self.name
        ack.destination_address = val.source_address
        print("ack", ack)
        # if not self.out_queue.empty(): # ? Added
        #     del self.out_queue # ? Added
        #     self.out_queue = Queue() # ? Added
        await self.out_queue.put(ack)

async def main():
    s1 = Sender("Sender 1", 4)
    s2 = Sender("Sender 2", 4)
    c = Channel()
    r1 = Receiver("Receiver 1")
    r2 = Receiver("Receiver 2")
    frames1 = []
    frames2 = []
    for _ in range(11):
        f = Frame()
        f.source_address = "Sender 1"
        f.destination_address = "Receiver 1"
        f.packFrame()
        frames1.append(f)

    for _ in range(11):
        f = Frame()
        f.source_address = "Sender 2"
        f.destination_address = "Receiver 2"
        f.packFrame()
        frames2.append(f)

    t1 = asyncio.create_task(s1.send(frames1, c))
    t2 = asyncio.create_task(r1.conn(c))
    t3 = asyncio.create_task(s2.send(frames2, c))
    t4 = asyncio.create_task(r2.conn(c))

    await t1
    await t2
    await t3
    await t4

if __name__ == "__main__":
    asyncio.run(main())
        