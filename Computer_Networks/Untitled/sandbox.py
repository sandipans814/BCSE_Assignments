import asyncio
from queue import Queue
import multiprocessing
import random
from frame import Frame

# change dictionary instances to queue

class Sender():
    def __init__(self, name: str):
        self.name = name
        self.frames = None

    async def send(self, frame: 'Frame', storage_dict, lock: asyncio.Lock, channel):
        await lock.acquire()
        await channel.place(storage_dict, frame.destination_address, frame, lock)
        lock.release()
        print(self.name,"\t:\tFrame sent in the channel!")

    async def recv(self, storage_dict, lock: asyncio.Lock, channel: 'Channel'):
        await lock.acquire()
        print(storage_dict)
        val: Frame = await channel.transmit(storage_dict, self.name)
        lock.release()
        return val

    async def func(self, frames: list, storage_dict, lock: asyncio.Lock, channel: 'Channel'):
        await asyncio.sleep(1)
        self.frames = frames
        print(self.name, "\t:\tFrames received from network layer!")
        await self.send(self.frames[0], storage_dict, lock, channel)
        print(self.name, "\t:\tWaiting for acknowledgement...")
        await asyncio.sleep(5)
        try:
            ack = await asyncio.wait_for(channel.transmit(storage_dict, self.name), timeout=1)
            if ack.getData() == '1':
                print(self.name, "  :\t Acknowledgement received.")
            else:
                print(self.name, "  :\t Acknowledgement corrupted.")
        except asyncio.TimeoutError as e:
            print("Timed out!", e)

class Channel():
    async def place(self, storage_dict, name, frame, lock):
        await lock.acquire()
        await asyncio.sleep(0.5)
        storage_dict[name] = frame
        lock.release()

    async def transmit(self, storage_dict, name):
        await asyncio.sleep(0.5)
        return storage_dict[name]

class Receiver():
    def __init__(self, name):
        self.name = name

    async def send(self, frame: 'Frame', storage_dict, lock, channel: 'Channel'):
        print('inside send receiver')
        await asyncio.wait_for(lock.acquire(), timeout=1)
        await channel.place(storage_dict, frame.destinaton_address, frame)
        print(self.name, "\t:\tSent!")
        lock.release()

    async def recv(self, storage_dict, lock, channel: 'Channel'):
        await asyncio.sleep(1)
        print(self.name,"\t:\tWaiting for frame")
        await lock.acquire()
        try:
            val: Frame = await asyncio.wait_for(channel.transmit(storage_dict, self.name), timeout = 1)
            await asyncio.sleep(5)
            print("Frame was received! Sending ACK...")
            ack = Frame()
            ack.source_address = self.name
            ack.destination_address = val.source_address
            ack.setData('1')
            print(ack.getData())
            await asyncio.wait_for(channel.place(storage_dict, ack.destination_address, ack, lock), timeout = 1)
            # await asyncio.wait_for(self.send(ack, storage_dict, lock, channel), timeout=0.05)
        except asyncio.TimeoutError as e:
            print(self.name, '\t:\tTimed Out!', e)
        lock.release()

async def main():
    manager = multiprocessing.Manager()
    storage_dict = manager.dict()
    lock = asyncio.Lock()
    s1 = Sender("Sender 1")
    s2 = Sender("Sender 2")
    s3 = Sender("Sender 3")
    r1 = Receiver("Receiver 1")
    r2 = Receiver("Receiver 2")
    r3 = Receiver("Receiver 3")
    c = Channel()
    f1 = Frame()
    f2 = Frame()
    f3 = Frame()
    f1.source_address = "Sender 1"
    f1.destination_address = "Receiver 1"
    f2.source_address = "Sender 2"
    f2.destination_address = "Receiver 2"
    f3.source_address = "Sender 3"
    f3.destination_address = "Receiver 3"
    frames1 = [f1.packFrame()]
    frames2 = [f2.packFrame()]
    frames3 = [f3.packFrame()]
    t1 = asyncio.create_task(s1.func(frames1, storage_dict, lock, c))
    t2 = asyncio.create_task(s2.func(frames2, storage_dict, lock, c))
    t3 = asyncio.create_task(s3.func(frames3, storage_dict, lock, c))

    await t1
    await t2
    await t3

    t4 = asyncio.create_task(r1.recv(storage_dict, lock, c))
    t5 = asyncio.create_task(r2.recv(storage_dict, lock, c))
    t6 = asyncio.create_task(r3.recv(storage_dict, lock, c))

    await t4
    await t5
    await t6

if __name__ == "__main__":
    
    asyncio.run(main())


