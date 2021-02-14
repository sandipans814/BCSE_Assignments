import eventlet
import socketio
import time
import random

sio = socketio.Server()
app = socketio.WSGIApp(sio)

@sio.event
def connect(sid, environ):
    print('connect ', sid)

@sio.on("sender-connected")
def sender_connected(sid,data):
    print("Sender Connected")

@sio.on("receiver-connected")
def receiver_connected(sid,data):
    print("Receiver Connected")

@sio.on("sender-to-channel")
def sender_to_channel(sid,data):
    print(f"Sending to receiver")
    time.sleep(random.randint(1, 3))
    sio.emit("channel-to-receiver", data)

@sio.on("receiver-to-channel")
def receiver_to_channel(sid,data):
    time.sleep(random.randint(1, 3))
    sio.emit('channel-to-sender', data)

@sio.event
def my_message(sid, data):
    print('message ', data)

@sio.event
def disconnect(sid):
    print('disconnect ', sid)

if __name__ == '__main__':
    eventlet.wsgi.server(eventlet.listen(('', 5000)), app)