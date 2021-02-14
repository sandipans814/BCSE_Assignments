import socketio
import pickle
from frame import Frame
from methods import *

sio = socketio.Client()

old_frame = 3

win_not_done = True

seq_no = [None, None, None, None]

@sio.event
def connect():
    print('connection established')
    sio.emit('receiver-connected',{})

@sio.on("channel-to-receiver")
def channel_to_receiver(data):
    global old_frame
    global win_not_done
    global seq_no
    temp = pickle.loads(data['data'])
    frame_no = temp.payload['seq_no'] % 4
    if win_not_done:
        print(frame_no, seq_no[frame_no])
        if seq_no[frame_no] is None:
            # TODO Corruption Check
            if crc_check(temp.payload["data"], temp.crc):
                print(f"Received from channel : {temp}")
                old_frame = temp.payload['seq_no']
                ack_frame = Frame()
                seq_no[frame_no] = 1
                ack_frame.payload['seq_no'] = temp.payload['seq_no']
                ack_frame.payload['nak'] = False
                sio.emit('receiver-to-channel', {'data' : pickle.dumps(ack_frame)})
            else:
                ack_frame = Frame()
                ack_frame.payload['seq_no'] = temp.payload['seq_no']
                ack_frame.payload['nak'] = True
                sio.emit('receiver-to-channel', {'data' : pickle.dumps(ack_frame)})
        else:
            print("Packet Discarded")
            ack_frame = Frame()
            ack_frame.payload['seq_no'] = temp.payload['seq_no']
            ack_frame.payload['nak'] = False
            sio.emit('receiver-to-channel', {'data' : pickle.dumps(ack_frame)})
    if seq_no[0] and seq_no[1] and seq_no[2] and seq_no[3]:
        print("Window Successful")
        win_not_done = True
        seq_no = [None, None, None, None]

@sio.on("sel-rep-done")
def done(data):
    print("Done")
    sio.disconnect()

@sio.event
def disconnect():
    print('disconnected from server')

sio.connect('http://localhost:5000')
sio.wait()