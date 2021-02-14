import random

class Frame:
    def __init__(self):
        #physical layer
        self.preamble = '01' * 7 * 8
        self.start_frame_delimiter = '10101011'
        #DLL
        self.destination_address = ''
        self.source_address = ''
        self.length = 46 * 8
        self.payload = {
            'header': '', #add a data length here
            'length': 0,
            'data': '0' * 46 * 8
        }
        self.crc = ''

    def CRCGetDivisor(self, powers: list):
        length = powers[0] + 1
        divisor = list('0' * length)
        for i in powers:
            divisor[i] = '1'
        divisor.reverse()
        divisor = "".join(divisor)
        return divisor

    def CRCGetRemainder(self, data, divisor, padding_type):
        divisor = divisor.lstrip('0')
        len_input = len(data)
        initial_padding = padding_type * (len(divisor) - 1)
        input_padded_array = list(data + initial_padding)
        while '1' in input_padded_array[:len_input]:
            cur_shift = input_padded_array.index('1')
            for i in range(len(divisor)):
                input_padded_array[cur_shift + i] = str(int(divisor[i] != input_padded_array[cur_shift + i]))
        return ''.join(input_padded_array)[len_input:]

    def setData(self, data):
        self.payload['length'] = len(data)
        if(len(data) < 46 * 8):
            # int(self.payload['data'], 2) | 
            self.payload['data'] = (bin(int(data, 2))[2:])
            self.payload['data'] = self.payload['data'].zfill(self.length)
        elif(len(data) > 1500 * 8):
            self.payload['data'] = (bin(int(data, 2) & int('1' * 1500 * 8, 2))[2:])
            self.length = 1500 * 8
        else:
            self.payload['data'] = data
            self.length = len(self.payload['data'])

    def getData(self):
        return self.payload['data'][ -self.payload['length'] : ]

    def calculateCRC(self):
        divisor = self.CRCGetDivisor([32, 26, 23, 22, 16, 12, 11, 10, 8, 7, 5, 4, 2, 1, 0]) # CRC-32-IEEE802.3
        padding_type = '0'
        self.crc = self.CRCGetRemainder(self.payload['data'], divisor, padding_type)

    def __str__(self):
        # return f'Preamble: {self.preamble}\nStart Frame Delimiter: {self.start_frame_delimiter} \
        #   \nLength: {self.length}\nPayload[Header]: {self.payload["header"]}\nPayload[Data]: {self.payload["data"]}\n'
        return self.getData()

    def __len__(self):
        if self.length < 46 * 8:
            return 64 * 8
        elif self.length > 46 * 8 and self.length < 1500 * 8:
            return (self.length - 46 * 8) + 64 * 8
        else:
            return 1518 * 8

    def packFrame(self):
        self.setData(getRandomString(8))
        self.calculateCRC()
        return self
        
def getRandomString(size):
    s = ""
    for i in range(0, size):
        s += str(random.randint(0, 1))
    return s

if __name__ == "__main__":
    f = Frame()
    f.packFrame()
    print(f.getData())
    print(f)