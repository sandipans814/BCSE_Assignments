import random
# import matplotlib.pyplot as plt
import math
import pickle

from methods import *

class Frame:
    meta = []
    lrc = ''
    def __init__(self):
        self.dataWordLength = 0
        self.codeWordLength = 0
        self.data = ''

    def pack(self, dataWordLength, codeWordLength, data):
        self.dataWordLength = dataWordLength
        self.codeWordLength = codeWordLength
        self.data = data
    
    def getDataWord(self):
        return data[0 : self.codeWordLength]

    def setMeta(self, metadata):
        meta = metadata

    def setLRC(self, lrc_value):
        lrc = lrc_value

if __name__ == "__main__":
    scheme = input("Enter your required scheme: VRC, LRC, Checksum, CRC: ")
    if scheme == 'VRC':
        length = int(input("Enter dataword size: "))
        message_list = sender('myfile.txt', length, 'VRC')
        pickle.dump(message_list, open('file.pkl', 'wb'))

        channel_stream = pickle.load(open('file.pkl', 'rb'))
        print("Sender stream :   ", channel_stream)
        error_stream = channel(channel_stream, error_type="Burst")

        pickle.dump(error_stream, open('file.pkl', 'wb'))

        receiver_stream = pickle.load(open('file.pkl', 'rb'))
        print("Receiver stream : ", receiver_stream)

        receiver(receiver_stream)

    elif scheme == 'LRC':
        length = int(input("Enter dataword size: "))
        message_list = sender('myfile.txt', length, 'LRC')
        pickle.dump(message_list, open('file.pkl', 'wb'))

        lrc = LRC_Util(message_list)

        channel_stream = pickle.load(open('file.pkl', 'rb'))
        print("Sender stream :   ", channel_stream)
        error_stream = channel(channel_stream, error_type="Burst", burst_size = 4)

        pickle.dump(error_stream, open('file.pkl', 'wb'))

        receiver_stream = pickle.load(open('file.pkl', 'rb'))

        print("Receiver stream : ", receiver_stream)

        receiver(receiver_stream, scheme = 'LRC', lrc = lrc)

    elif scheme == 'Checksum':
        length = int(input("Enter dataword size: "))
        message_list = sender('myfile.txt', length, 'Checksum')
        chksum = my_checksum(message_list)

        message_list.append(chksum)
        pickle.dump(message_list, open('file.pkl', 'wb'))

        channel_stream = pickle.load(open('file.pkl', 'rb'))
        print("Sender stream :   ", channel_stream)
        error_stream = channel(channel_stream, error_type="Burst", burst_size = 3)

        pickle.dump(error_stream, open('file.pkl', 'wb'))

        receiver_stream = pickle.load(open('file.pkl', 'rb'))

        print("Receiver stream : ", receiver_stream)
        print(chksum)

        receiver(receiver_stream, scheme="Checksum")
    elif scheme == 'CRC':
        length = 7
        div = CRC_get_divisor([16, 15, 2, 0])

        message_list = sender('myfile.txt', length, 'CRC')

        pickle.dump(message_list, open('file.pkl', 'wb'))

        channel_stream = pickle.load(open('file.pkl', 'rb'))
        print("Sender stream :   ", *channel_stream)
        error_stream = burst_error(channel_stream, burst_size = 20)

        pickle.dump(error_stream, open('file.pkl', 'wb'))
        
        receiver_stream = pickle.load(open('file.pkl', 'rb'))
        print("Receiver stream : ", *receiver_stream)

        rem = crc_remainder(message_list, div, '0')
        receiver(receiver_stream, scheme="CRC", divisor = div, crc = rem)


    else:
        print("Entering interactive test mode...")

    #tests

    #a
    # x = '1010011'
    # x_par = '10100110'
    # y = '1000011'
    # y_par = '10000110'
    # div = CRC_get_divisor([16, 15, 2, 0])
    
    # VRC(y_par)
    
    # lrc_val = LRC_Util([x])
    # print(lrc_val)
    # LRC([y], lrc_val)
    
    # chk = my_checksum([x])
    # print(chk)
    # print(my_checksum([y, chk]))

    # rem = crc_remainder(x, div, '0')
    # print(crc_check(y, div, rem))

    # #c
    # d = '100'
    # x = '101010'
    # x_par = '1010101'
    # r = crc_remainder(x, d, '0')
    # y = '101000'
    # crc_check(y, d, r) # True, shouldn't be the case
    # crc_check(x, d, r) # True, as required

    # chk = my_checksum([x])
    # print(my_checksum([y, chk]))
    # y_par = '1010001'
    # VRC(y_par) # An error was detected


