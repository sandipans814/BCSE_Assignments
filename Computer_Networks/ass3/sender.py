import common as co
import time
import socket
import random
import time
import pickle
import threading
from frame import Frame

isBusyChannel = 0
# Socket to send data to channel
sockSend = co.createConn(co.portSenderReceive)

time.sleep(1)
# Socket to send data to channel
sockSignal = co.createConn(co.portSenderSignal)

print('Connected to channel')

p= 0.0

persistent_type = input('Enter algo type: ')
if persistent_type == "p":
    p = float(input("Enter value of p: "))

probab = 100
timeSlot = 2

# Function to send frames


def send_frame(list_of_frames):

    i = 0
    global persistent_type
    while(True):
        # Sense the channel and check if flag is 1 then dont send
        if persistent_type == '1':
            if(isBusyChannel == 0):
                print('Sending frame '+str(i))
                co.send_frame(list_of_frames[i], sockSend)
                if(list_of_frames[i] != '#'):
                    i = i+1
                else:
                    break
                time.sleep(3)
            else:
                print('Channel busy')
                continue
        elif persistent_type == 'Non':
            if(isBusyChannel == 1):
                t = random.randint(1, 4)
                print("Waiting ", t)
                time.sleep(t)
            else:
                print('Sending frame '+str(i))
                co.send_frame(list_of_frames[i], sockSend)
                if(list_of_frames[i] != '#'):
                    i = i+1
                else:
                    break
                time.sleep(3)
        else:
            if(isBusyChannel == 0):  # Channel is free
                # Send the frame with a probability p
                pr = random.randint(0, probab) * 0.01
                if(pr <= p):
                    # Send the frame
                    print('Sending frame '+str(i))
                    co.send_frame(list_of_frames[i], sockSend)
                    if(list_of_frames[i] != '#'):
                        i = i+1
                    else:
                        break
                    time.sleep(3)
                else:
                    print('Waiting '+str(timeSlot))
                    time.sleep(timeSlot)
                    continue

            else:  # Channel is busy
                print('Channel busy')
                time.sleep(2)
                continue


# Function to sense the medium
def sense_medium():
    global isBusyChannel

    while(True):
        if(sockSignal.recv(1024).decode() == '1'):
            # Means channel is busy
            isBusyChannel = 1
        else:
            # Means channel is not busy
            isBusyChannel = 0


list_of_frames = co.readfile('input.txt', co.frame_size)
# list_of_frames = []
# for i in range(5):
#     f = Frame()
#     f.packFrame()
#     list_of_frames.append(f)

list_of_frames.append('#')

sendThread = threading.Thread(target=send_frame, args=(
    list_of_frames,))  # create the sending thread
senseThread = threading.Thread(
    target=sense_medium)  # create the sending thread

sendThread.start()
senseThread.start()

sendThread.join()
sendThread.join()

