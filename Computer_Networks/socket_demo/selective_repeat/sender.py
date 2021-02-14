import socketio
import threading
from multiprocessing import Process
import time
from frame import Frame
import pickle

sio = socketio.Client()

ini_time = None

ack = False

acks = [False, False, False, False]

old_frame = 3 

ini_frame = 0

delay = 6

b_data = None

done = False

nak = [False,False,False,False]

check_time = time.time()

frames = []
for i in range(10):
    f = Frame()
    f.packFrame()
    f.payload['seq_no'] = i%8
    frames.append(f)

def successful_received(no):
    global frames
    global acks
    global done
    global nak
    print(f"Ack : {no}") 
    if acks[0] and acks[1] and acks[2] and acks[3]:
        done = True
        acks = [False, False, False, False]
        nak = [False, False, False, False]

def timeout(delay,no):   
    global ack
    global nak
    ini = time.time()
    while not acks[no]:
        if delay < time.time() - ini or nak[no]:
            if not nak[no] :
                print("Timeout...! Retransmitting")
            nak[no] = False
            return
    successful_received(no)


@sio.event
def connect():
    print('connection established')
    sio.emit('sender-connected',{})

@sio.event
def my_message(data):
    print('message received with ', data)
    sio.emit('my response', {'response': 'my response'})

@sio.on("channel-to-sender")
def channel_to_sender(data):
    global check_time
    global ack
    global b_data
    global delay

    temp = pickle.loads(data['data'])
    seq_no = temp.payload['seq_no'] % 4
    if not temp.payload['nak']:
        acks[seq_no] = True
    else:
        nak[seq_no] = True
        print(f"NAK : {seq_no}")
    b_data = data

@sio.event
def disconnect():
    print('disconnected from server')


def send_data(frame, no):
    global ack
    global frames
    global check_time
    global ini_time
    global delay
    global ini_frame
    if True:
        check_time = time.time()
        print(f"sending : {frame.payload['seq_no']}")
        if ini_time is None:
            ini_time = time.time()
        sio.emit('sender-to-channel', {"data" : pickle.dumps(frame)})
        p = threading.Thread(target = timeout, args = (delay,no))
        p.start()
        p.join()

def window():
    global frames
    global done
    global ini_frame
    global acks
    p0 = threading.Thread(target = send_data, args = (frames[0],0))
    p0.start()
    if len(frames)>1:
        p1 = threading.Thread(target = send_data, args = (frames[1],1))
        p1.start()
    if len(frames)>2:
        p2 = threading.Thread(target = send_data, args = (frames[2],2))
        p2.start()
    if len(frames)>3:
        p3 = threading.Thread(target = send_data, args = (frames[3],3))
        p3.start()
    while not (acks[0] and (acks[1] or len(frames)<2) and (acks[2] or len(frames)<3) and (acks[3] or len(frames)<4)):
        if not acks[0]:
            if not p0.is_alive():
                p0 = threading.Thread(target = send_data, args = (frames[0],0))
                p0.start()
        if len(frames) > 1 and not acks[1]:
            if not p1.is_alive():
                p1 = threading.Thread(target = send_data, args = (frames[1],1))
                p1.start()
        if len(frames) > 2 and not acks[2]:
            if not p2.is_alive():
                p2 = threading.Thread(target = send_data, args = (frames[2],2))
                p2.start()
        if len(frames) > 3 and not acks[3]:
            if not p3.is_alive():
                p3 = threading.Thread(target = send_data, args = (frames[3],3))
                p3.start()
    done = False

if __name__ == '__main__':
    sio.connect('http://localhost:5000')
    i = 0
    while len(frames):
        window()
        try:
            frames = frames[4:]
        except:
            break
    print("done")
    sio.emit('sel-rep-done-channel',{})
    time.sleep(6)
    print("Task Successful")
    input("Exit")
    sio.disconnect()