from __future__ import absolute_import
import typing
import textwrap
import random
import math
import numpy as np

get_binary = lambda x: bin(x)[2:]

get_char = lambda x: chr(int(x, 2))

threshold = 0.6

def compose(f, g):
    return lambda x: f(g(x))

def sigmoid(z):
    return 1 / (1 + math.exp(-z))

def zero_padding(s):
    if len(s) == 7:
        return s
    elif len(s) < 7:
        return ('0'* (7 - len(s)) + s)

def pad_zeroes_2(s, length):
    if len(s) == length:
        return s
    elif len(s) < length:
        return '0' * (length - len(s)) + s
    else:
        raise ValueError("len(s) should be <= length paramater")

def  count_set_bits(n): 
    count = 0
    while (n): 
        count += n & 1
        n >>= 1
    return count

def parity_bit_generator(s, flag = 'even'):
    no_of_ones = count_set_bits(int(s, 2))
    if flag == 'even':
        return '1' if no_of_ones & 1 else '0'
    elif flag == 'odd':
        return '0' if no_of_ones & 1 else '1'
    else:
        raise AttributeError("Invalid type")

def parity_checker(s, flag = 'even'):
    no_of_ones = count_set_bits(int(s[:-1], 2))
    if flag == 'even':
        if no_of_ones & 1 and s[-1] == '1':
            return True
        elif not no_of_ones & 1 and s[-1] == '0':
            return True
        return False
    elif flag == 'odd':
        if no_of_ones & 1 and s[-1] == '0':
            return True
        elif not no_of_ones & 1 and s[-1] == '1':
            return True
        return False

def message_encoder(s: str, k: int) -> list:
    letters = list(map(lambda x : compose(zero_padding, get_binary)(x), list(s)))

    encoded_string = ''.join(letters)
    encoded_list = textwrap.wrap(encoded_string, k)
    return encoded_list


def single_bit_error(dataword):
    key = random.randint(0, len(dataword) - 1)
    dataword = list(dataword)
    z = random.randrange(-10, 10)
    probs = sigmoid(z)
    if probs < threshold:
        dataword[key] = '1' if dataword[key] == '0' else '0'
    dataword = "".join(dataword)
    return dataword

def burst_error(dataword, burst_size = 2):
    if(len(dataword) < burst_size):
        print('Invalid burst size')
        return
    start = random.randint(0, len(dataword) - burst_size - 1)
    end = start + burst_size
    dataword = list(dataword)
    x = random.randrange(-10, 10)
    outer_probs = sigmoid(x)
    if outer_probs < threshold + 0.1:
        for i in range(start, end + 1):
            z = random.randrange(-10, 10)
            probs = sigmoid(z)
            if probs < threshold:
                dataword[i] = '1' if dataword[i] == '0' else '0'
    return "".join(dataword)

###VRC ERROR DETECTION####

def VRC(codeword, parity_type = "even"):
    dataword = codeword[:-1]
    parity_bit = codeword[-1]
    received_word_parity_check_bit = parity_bit_generator(dataword, parity_type)
    if parity_bit == received_word_parity_check_bit:
        print("No Error. Accepted")
        return dataword
    else:
        print("An error was detected")

### LRC ERROR DETECTION ###
def LRC_Util(stream):
    lrc = 0
    for i in stream:
        lrc ^= int(i, 2)
    if lrc == 0:
        return '0' * len(stream[0])
    return pad_zeroes_2(get_binary(lrc), len(stream[0]))

def LRC(stream, lrc_value):
    received_stream_lrc = LRC_Util(stream)
    print(lrc_value, received_stream_lrc)
    if received_stream_lrc == lrc_value:
        print("No error. Accepted")
    else:
        print("An error was detected")


### CHECKSUM ERROR DETECTION ###

def add_binary_nums(x, y): 
        max_len = max(len(x), len(y)) 
        x = x.zfill(max_len) 
        y = y.zfill(max_len) 
        result = ''
        carry = 0
        for i in range(max_len - 1, -1, -1): 
            r = carry 
            r += 1 if x[i] == '1' else 0
            r += 1 if y[i] == '1' else 0
            result = ('1' if r % 2 == 1 else '0') + result
            carry = 0 if r < 2 else 1     # Compute the carry. 
        if carry != 0 : result = add_binary_nums(result, '1') 
        return result.zfill(max_len)

def my_checksum(stream):
    result = stream[0]
    for i in range(1, len(stream)):
        result = add_binary_nums(result, stream[i])
    return "".join(['1' if i == '0' else '0'for i in result])

### CRC ###

def CRC_get_divisor(powers: list): # [16,15,2,0]
    length = powers[0] + 1
    divisor = list('0' * length)
    for i in powers:
        divisor[i] = '1'
    divisor.reverse()
    divisor = "".join(divisor)
    return divisor

def crc_remainder(inp, poly, padding):

    poly = poly.lstrip('0')
    len_input = len(inp)
    initial_padding = padding * (len(poly) - 1)
    input_padded_array = list(inp + initial_padding)
    while '1' in input_padded_array[:len_input]:
        cur_shift = input_padded_array.index('1')
        for i in range(len(poly)):
            input_padded_array[cur_shift + i] = str(int(poly[i] != input_padded_array[cur_shift + i]))
    return ''.join(input_padded_array)[len_input:]

def crc_check(inp, poly, check_value):

    poly = poly.lstrip('0')
    len_input = len(inp)
    initial_padding = check_value
    input_padded_array = list(inp + initial_padding)
    while '1' in input_padded_array[:len_input]:
        cur_shift = input_padded_array.index('1')
        for i in range(len(poly)):
            input_padded_array[cur_shift + i] = str(int(poly[i] != input_padded_array[cur_shift + i]))
    return ('1' not in ''.join(input_padded_array)[len_input:])

### SENDER ###

def sender(file, length, scheme = 'VRC'):
    msg = open(file, 'rb').read()
    message = message_encoder(msg, length)
    message_for_crc = "".join(message)
    
    message = list(map(lambda x: pad_zeroes_2(x, length), message))
    if scheme == 'VRC':
        '''
            Redundant bits are added to the end of each dataword. VRC needs 1 redundant bit, which stores the parity. 
        '''
        parity_array = list(map(lambda x: parity_bit_generator(x), message))
        parity_added_msg = list(map(lambda x, y: x + y, message, parity_array))
        return parity_added_msg
    
    elif scheme == 'LRC':
        return message
    
    elif scheme == 'Checksum':
        return message
    
    elif scheme == 'CRC':
        return message_for_crc
    
    else:
        raise TypeError("No such scheme was found.")

### CHANNNEL ###

def channel(stream, error_type = "Single bit", burst_size = 2):
    if error_type == "Single bit":
        stream = list(map(single_bit_error, stream))
    elif error_type == 'Burst':
        stream = list(map(lambda x: burst_error(x, burst_size), stream))
    else:
        raise TypeError('Invalid Error Type')
    return stream

### RECEIVER ####
def receiver(stream, scheme = 'VRC', lrc = None, divisor = None, crc = None):
    if scheme == 'VRC':
        for i, d in enumerate(stream, 0):
            dataword = VRC(d, parity_type = "even")
            if dataword:
                print(i, dataword)
    elif scheme == 'LRC':
        if not lrc:
            print("LRC for sender is required!")
            return
        LRC(stream, lrc)
    elif scheme == 'Checksum':
        chk = my_checksum(stream)
        print(chk)
        if '1' in chk:
            print("Error was detected.")
        else:
            print("No Error. Accepted")
    elif scheme == "CRC":
        if not divisor or not crc:
            print("Incomplete data for CRC calculation!")
            return
        print(crc_check(stream, divisor, crc))
