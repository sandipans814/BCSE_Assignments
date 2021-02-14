import random
from math import log,ceil
walsh = []
class Station :
    def __init__(self,stn_num,num_data,cdma_code,frames):
        self.stn_num = stn_num
        self.num_data = num_data
        self.cdma_code = cdma_code
        self.frames = frames
    
    def sendData(self,index):
        if(self.frames[index]=="i"):
            data = 0
        if(self.frames[index]==0):
            data = -1
        else:
            data = 1
        codeword=[data*self.cdma_code[i] for i in range(len(self.cdma_code))]
        print("Station "+str(self.stn_num)+"sending codeword"+str(codeword))
        return codeword

# Function to create walsh tables
def createWalsh(r):
	global walsh
	walsh=[[int(bin(x&y),13)%2 or -1 for x in range(r)]for y in range(r)]



def simulate():
    num_stn = int(input("Enter number of station in power of 2 : "))
    max_num_stn = 2**ceil(log(num_stn,2))

    num_data = int(input("Enter number of data per station : "))

    createWalsh(max_num_stn)
    print(walsh)

    stns = []
    for i in range(num_stn):
        frames = input("Enter data for station "+str(i+1)+": ")
        frames = list(frames)

        tempstn = Station(stn_num,num_data,walsh[i],frames)
        stns.add(tempstn)
    
    for i in range (num_stn,max_num_stn):
        frames = list(num_data*'i')
        tempstn = Station(stn_num,num_data,walsh[i],frames)
        stns.append(tempstn)
    
    print()

    for i in range(num_data):
        




simulate()

