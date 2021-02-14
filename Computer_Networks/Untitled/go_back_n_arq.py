import asyncio
from asyncio import Queue
import random
from frame import Frame

# TODO : Discuss the Go Back N algorithm thoroughly.
# ? Use 2 queues for each Node, if no other solution comes to mind.

class Channel():
    def __init__(self):
        self.senders = []
        self.receivers = []

    async def connect(self, node) -> None:
        if isinstance(node, 'Sender') and node not in self.senders:
            self.senders.append(node)
            print(node.name, "   :\thas joined the channel.")
        elif isinstance(node, 'Receiver') and node not in self.receivers:
            self.receivers.append(node)
            print(node.name, " :\thas joined the channel.")

    async def transmit(self, node):
        pass

class Sender():
    def __init__(self, name, window_size):
        '''
        Sender class: takes name, and window size, as arguments.
        '''
        self.name = name
        self.queue = Queue()
        self.window_size = window_size
        self.window_start = 0
        self.window_end = self.window_start + self.window_size

    def set_sequence_no(self, frames):
        for i in range(0, len(frames)):
            frames[i].payload["seq_no"] = i % self.window_size
        return frames
    
    async def send(self, frames: list, channel: 'Channel'):
        frames = self.set_sequence_no(frames)
        current_frames = frames[self.window_start: self.window_end] # ? len(current_frames) = 3
        print(self.name, "   :\t sending first batch of frames, window size:", self.window_size)
        for i in range(0, len(current_frames)):
            await self.queue.put(current_frames[i]) # ? queue gets [f1, f2, f3,]
        print(self.queue)
        frame_number = len(current_frames) - 1 # ? 2
        while frame_number < len(frames): # ? 2 < 10 (say)
            # copy = self.frames[i]
            # print(copy)
            while True:
                if self.queue.empty():
                    await self.queue.put(current_frames) # ? queue gets [[f1, f2, f3,]]
                else: # ? queue ta probs delete kora jabena, incoming, outgoing duto rakhte hobe.
                    del self.queue
                    self.queue = asyncio.Queue()
                    await self.queue.put(current_frames) # ? queue gets [[f1, f2, f3,]]
                print(self.name, "   :\tFrame with seq no.", current_frames[i].payload['seq_no'], "sent in the channel!")
                try:
                    await asyncio.wait_for(channel.transmit(self), timeout = 10)
                    val = await asyncio.wait_for(self.queue.get(), timeout = 10)
                    if current_frames[0].payload['seq_no'] == val: # ? val is ack seq_no
                        print(self.name, "   :\thas received", val, "from", val.source_address)
                        del(current_frames[0])
                        frame_number = frame_number + 1
                        current_frames.append(frames[frame_number])
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



async def main():
    s1 = Sender("Sender 1", 5)
    c = Channel()
    frames = []
    for _ in range(11):
        f = Frame()
        f.packFrame()
        frames.append(f)

    t1 = asyncio.create_task(s1.send(frames, c))
    
    # print([str(f) for f in frames])

if __name__ == "__main__":
    asyncio.run(main())
