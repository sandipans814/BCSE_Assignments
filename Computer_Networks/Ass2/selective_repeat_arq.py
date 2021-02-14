import asyncio
import random
from asyncio import Queue
from frame import Frame
import functools
from methods import single_bit_error, crc_check

class Channel:

    def __init__(self):
        self.senders = []
        self.receivers = []

    async def connect(self, node):
        if isinstance(node, Sender) and node not in self.senders:
            self.senders.append(node)
        elif isinstance(node, Receiver) and node not in self.receivers:
            self.receivers.append(node)
        print(f"{node.name}\t:\thas joined the channel")

    async def transmit(self, node):
        await asyncio.sleep(1)
        if node not in self.senders:
            print("Channel      :\tPlease join the channel first!")
        else:
            await asyncio.sleep(1)
            f = await node.out_queue.get()
            print(f)
            f.setData(single_bit_error(f.payload['data']))
            print(f)
            r = list(filter(lambda x: x.name == f.destination_address, self.receivers))[0]
            await r.in_queue.put(f)
            while not node.out_queue.empty():
                f = await node.out_queue.get()
                x = random.randrange(-1, 3)
                print("Random selector : ", x)
                if(x < 0):
                    try:
                        f = await asyncio.wait_for(node.out_queue.get(), timeout = 1)
                    except:
                        pass
                    print(f)
                r = list(filter(lambda x: x.name == f.destination_address, self.receivers))[0]
                await r.in_queue.put(f)
            await asyncio.sleep(2)
            await r.recv()
            await asyncio.sleep(2)
            while not r.out_queue.empty():
                val = await r.out_queue.get()
                print(val.payload['type'])
                await node.in_queue.put(val)
            


class Sender:

    def __init__(self, name, window_size):
        self.name = name
        self.window_size = window_size
        self.window_start = 0
        self.window_end = self.window_start + self.window_size - 1
        self.in_queue = Queue()
        self.out_queue = Queue()

    def set_sequence_no(self, frames):
        for i in range(0, len(frames)):
            frames[i].payload["seq_no"] = i % (self.window_size * 2)
        return frames

    async def send(self, frames: list, channel: 'Channel'):
        self.frames = self.set_sequence_no(frames)
        await channel.connect(self)
        current_frames = frames[self.window_start: self.window_size]
        print(list(map(lambda x: x.payload['seq_no'], current_frames)))
        bool_arr = [False for _ in current_frames]
        while self.window_end <= len(frames):
            if not current_frames:
                break
            for i in current_frames:
                await self.out_queue.put(i)
            while True:
                if not current_frames:
                    break
                try:
                    await asyncio.wait_for(channel.transmit(self), timeout=12)
                    if current_frames:
                        while not self.in_queue.empty():
                            val = await self.in_queue.get()
                            # print(val.payload)
                            try:
                                if val.payload['type'] == 'ACK':
                                    bool_arr[val.payload['seq_no'] % 4] = True
                                    print(self.name, ":\tACK for", val.payload['seq_no'], "received!")
                                elif val.payload['type'] == 'NAK':
                                    await self.out_queue.put(current_frames[val.payload['seq_no']])
                                    print(self.name, ":\tRetransmitting frame ",current_frames[val.payload['seq_no']].payload['seq_no'],"NAK received")
                                elif val.payload['type'] == '':
                                    await self.out_queue.put(current_frames[val.payload['seq_no']])
                                    print(self.name, ":\tRetransmitting frame ",current_frames[val.payload['seq_no']].payload['seq_no'],"lost frame")
                            except:
                                pass
                    print(bool_arr)
                    get_bool = False if False in bool_arr else True
                    print(get_bool)
                    if get_bool == True:
                        self.window_start += self.window_size
                        self.window_end += self.window_size
                        print(self.window_start, self.window_end)
                        if self.window_end <= len(frames):
                            current_frames = frames[self.window_start: self.window_end + 1]
                            bool_arr = [False for _ in current_frames]
                        else:
                            current_frames = frames[self.window_start:]
                            bool_arr = [False for _ in current_frames]
                        print(list(map(lambda x: x.payload['seq_no'], current_frames)))
                        if current_frames:
                            print(self.name, ":\tTransmitting next batch of size ",self.window_size)
                        break
                except asyncio.TimeoutError as e:
                    for i in range(len(bool_arr)):
                        if not bool_arr[i]:
                            await self.out_queue.put(current_frames[i])
        print(self.name, ":\tTransmission Complete!")

class Receiver:

    def __init__(self, name, window_size):
        self.name = name
        self.in_queue = Queue()
        self.out_queue = Queue()
        self.window_size = window_size
        self.window_start = 0
        self.window_end = self.window_start + self.window_size - 1
        self.buffer = []
        self.bool_arr = [False for _ in range(0, self.window_size)]
        self.visited_arr = [False for _ in range(0, self.window_size)]

    async def conn(self, channel: 'Channel'):
        await asyncio.sleep(1)
        await channel.connect(self)

    async def recv(self):
        while not self.in_queue.empty():
            val = await self.in_queue.get()
            # print(val.payload['data'], val.crc, crc_check(val.getData(), val.crc))
            if not crc_check(val.payload['data'], val.crc):
                ack = Frame()
                ack.setData('0')
                ack.payload['type'] = 'NAK'
                print('hello')
                ack.payload['seq_no'] = val.payload['seq_no']
                await self.out_queue.put(ack)
                self.visited_arr[val.payload['seq_no'] % 4] = True
            elif val.payload['seq_no'] not in self.buffer:
                self.buffer.append(val.payload['seq_no'])
                print(self.name, ":\treceived frame with seq no.", val.payload['seq_no'])
                ack = Frame()
                ack.setData('0')
                ack.payload['type'] = 'ACK'
                ack.payload['seq_no'] = val.payload['seq_no']
                await self.out_queue.put(ack)
                self.visited_arr[val.payload['seq_no'] % 4] = True
                self.bool_arr[val.payload['seq_no'] % 4] = True
        print("receiver bool array", self.bool_arr)
        for i in range(0, len(self.bool_arr)):
            ack = Frame()
            ack.setData('0')
            if self.visited_arr[i] == False:
                ack.payload['type'] = ''
                ack.payload['seq_no'] = i
                await self.out_queue.put(ack)
        get_bool = False if False in self.bool_arr else True
        if get_bool:
            self.buffer = []
            self.bool_arr = [False for _ in range(0, self.window_size)]
            self.visited_arr = [False for _ in range(0, self.window_size)]

async def main():
    s = Sender("Sender 1", 4)
    r = Receiver("Receiver 1", 4)
    c = Channel()

    frames = []
    for _ in range(11):
        f = Frame()
        f.source_address = "Sender 1"
        f.destination_address = "Receiver 1"
        f.packFrame()
        frames.append(f)

    t1 = asyncio.create_task(s.send(frames, c))
    t2 = asyncio.create_task(r.conn(c))

    await t1
    await t2

if __name__ == "__main__":
    asyncio.run(main())
