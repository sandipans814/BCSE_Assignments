import random
import math

threshold = 0.6

def sigmoid(z):
    return 1 / (1 + math.exp(-z))

def CRC_get_divisor(powers: list): # [16,15,2,0]
    length = powers[0] + 1
    divisor = list('0' * length)
    for i in powers:
        divisor[i] = '1'
    divisor.reverse()
    divisor = "".join(divisor)
    return divisor

def single_bit_error(dataword):
    key = random.randint(0, len(dataword) - 1)
    dataword = list(dataword)
    z = random.randrange(-10, 10)
    probs = sigmoid(z)
    if probs < threshold:
        dataword[key] = '1' if dataword[key] == '0' else '0'
    dataword = "".join(dataword)
    return dataword

def crc_check(inp, check_value, poly = CRC_get_divisor([32, 26, 23, 22, 16, 12, 11, 10, 8, 7, 5, 4, 2, 1, 0])):
    """Calculate the CRC check of a string of bits using a chosen polynomial."""
    poly = poly.lstrip('0')
    len_input = len(inp)
    initial_padding = check_value
    input_padded_array = list(inp + initial_padding)
    while '1' in input_padded_array[:len_input]:
        cur_shift = input_padded_array.index('1')
        for i in range(len(poly)):
            input_padded_array[cur_shift + i] = str(int(poly[i] != input_padded_array[cur_shift + i]))
    print(''.join(input_padded_array)[len_input:])
    return ('1' not in ''.join(input_padded_array)[len_input:])