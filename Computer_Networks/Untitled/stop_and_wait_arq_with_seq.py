import asyncio
from asyncio import Queue
import random
from frame import Frame

class Channel():
    def __init__(self):
        self.senders = list()
        self.receivers = list()

    async def connect(self, node) -> None:
        if isinstance(node, Sender) and node not in self.senders:
            self.senders.append(node)
            print(node.name, "   :\thas joined the channel.")
        elif isinstance(node, Receiver) and node not in self.receivers:
            self.receivers.append(node)
            print(node.name, " :\thas joined the channel.")

    async def transmit(self, node) -> None:
        if node not in self.senders:
            print("Channel      :\tPlease join the channel first!")
        else:
            await asyncio.sleep(random.randint(3, 4))
            f = await node.queue.get()
            r = list(filter(lambda x: x.name == f.destination_address, self.receivers))[0]
            if not r.queue.empty():
                del r.queue
                r.queue = asyncio.Queue()
            await r.queue.put(f)
            print("Channel     :\tsent to", r.name, "!")
            await asyncio.sleep(random.randint(3, 8))
            await r.recv(self)
            ack = await r.queue.get()
            await node.queue.put(ack)

class Sender():
    def __init__(self, name: str):
        self.name = name
        self.frames = None
        self.queue = Queue()

    def set_sequence_no(self, frames):
        for i in range(0, len(frames)):
            frames[i].payload['seq_no'] = str(i % 2)
        
        return frames

    async def send(self, frames: list, channel: 'Channel'):
        await asyncio.sleep(1)
        self.frames = self.set_sequence_no(frames)
        await channel.connect(self)
        print(self.name, "   :\tFrames received form network layer!")
        for i in range(0, len(frames)):
            copy = self.frames[i]
            # print(copy)
            while True:
                if self.queue.empty():
                    await self.queue.put(copy)
                else:
                    del self.queue
                    self.queue = asyncio.Queue()
                    await self.queue.put(copy)
                print(self.name, "   :\tFrame with seq no.", copy.payload['seq_no'], "sent in the channel!")
                try:
                    await asyncio.wait_for(channel.transmit(self), timeout = 10)
                    val = await asyncio.wait_for(self.queue.get(), timeout = 10)
                    if copy.payload['seq_no'] != val: # ? val is ack 0 or 1
                        print(self.name, "   :\thas received", val, "from", val.source_address)
                        break
                    else:
                        print(self.name, "   :\tACK Frame Corrupted!")
                        await asyncio.sleep(1)
                        print(self.name, "   :\tRetransmitting!")
                except asyncio.TimeoutError as e:
                    print(self.name, "   :\tTimed Out!")
                    await asyncio.sleep(1)
                    print(self.name, "   :\tRetransmitting!")
                await asyncio.sleep(3)

class Receiver():
    def __init__(self, name):
        self.name = name 
        self.queue = Queue()
        self.buffer = []

    async def conn(self, channel: 'Channel'):
        await asyncio.sleep(1)
        await channel.connect(self)

    async def recv(self, channel: 'Channel'):
        val = await asyncio.wait_for(self.queue.get(), timeout=5)
        if not self.buffer:
            self.buffer.append(val)
            print(self.name, " :\thas received frame with seq no.", val.payload['seq_no'], "from", val.source_address)
        elif self.buffer[-1].payload['seq_no'] == val.payload['seq_no']:
            print(self.name, " :\thas already received this frame, hence discarded.")
        else:
            print(self.name, " :\thas received frame with seq no.", val.payload['seq_no'], "from", val.source_address)
            self.buffer.append(val)
        ack = Frame()
        if val.payload['seq_no'] == '1':
            ack.setData("0")
        else:
            ack.setData('1')
        ack.source_address = self.name
        ack.destination_address = val.source_address
        await self.queue.put(ack)


async def main():
    s1 = Sender("Sender 1")
    r1 = Receiver("Receiver 1")
    s2 = Sender("Sender 2")
    r2 = Receiver("Receiver 2")
    c = Channel()
    f1 = Frame()
    f3 = Frame()
    f5 = Frame()
    f1.source_address = "Sender 1"
    f1.destination_address = "Receiver 1"
    f3.source_address = "Sender 1"
    f3.destination_address = "Receiver 1"
    f5.source_address = "Sender 1"
    f5.destination_address = "Receiver 1"
    f2 = Frame()
    f4 = Frame()
    f2.source_address = "Sender 2"
    f2.destination_address = "Receiver 2"
    f4.source_address = "Sender 2"
    f4.destination_address = "Receiver 2"
    frames1 = [f1.packFrame(), f3.packFrame(), f5.packFrame()]
    frames2 = [f2.packFrame(), f4.packFrame()]
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