import socketio
import threading
from multiprocessing import Process
import time
from frame import Frame
import pickle

sio = socketio.Client()

ini_time = None

ack = False

old_frame = 3 

delay = 4

b_data = None

done = False

check_time = time.time()

frames = []
for i in range(5):
    f = Frame()
    f.packFrame()
    f.payload['seq_no'] = i % 2
    frames.append(f)

def successful_received():
    global frames
    global ack
    print(b_data) 
    frames = frames[1:]
    ack = False

def timeout(delay):   
    global ack
    ini = time.time()
    while not ack:
        if delay < time.time() - ini:
            print("timeout")
            return
    successful_received()


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
    #  and check_time == pickle.loads(data['data']['time'])
    if old_frame == 3:
        delay = time.time() - ini_time
    if old_frame != temp.payload['seq_no']:
        ack = True
    b_data = data

@sio.event
def disconnect():
    print('disconnected from server')


def send_data():
    global ack
    global frames
    global done
    global check_time
    global ini_time
    global delay
    if (len(frames)):
        check_time = time.time()
        print("sending")
        if ini_time is None:
            ini_time = time.time()
        sio.emit('sender-to-channel', {"data" : pickle.dumps(frames[0])})
        p = threading.Thread(target = timeout, args = (delay,))
        p.start()
        p.join()
    else:
        done = True

if __name__ == '__main__':
    sio.connect('http://localhost:5000')

    while not done:
        send_data()
