import socketio
import pickle
from frame import Frame

sio = socketio.Client()

old_frame = 3

@sio.event
def connect():
    print('connection established')
    sio.emit('receiver-connected',{})

@sio.on("channel-to-receiver")
def channel_to_receiver(data):
    global old_frame
    temp = pickle.loads(data['data'])
    if old_frame != temp.payload['seq_no']:
        print(f"Received from channel : {temp}")
        old_frame = temp.payload['seq_no']
        ack_frame = Frame()
        if temp.payload['seq_no'] == 1:
            ack_frame.payload['seq_no'] = 0
        else:
            ack_frame.payload['seq_no'] = 1
        sio.emit('receiver-to-channel', {'data' : pickle.dumps(ack_frame)})
    else:
        print("Packet Discarded")
        ack_frame = Frame()
        ack_frame.payload['seq_no'] = 0 if old_frame else 1
        # sio.emit('receiver-to-channel', {'data' : pickle.dumps(ack_frame)})

@sio.event
def disconnect():
    print('disconnected from server')

sio.connect('http://localhost:5000')
sio.wait()