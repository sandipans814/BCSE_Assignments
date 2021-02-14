class Station: # Class for denoting every station
	
	def __init__(self, stn_num, num_data, cdma_code, frames):
		self.stn_num=stn_num
		self.num_data=num_data
		self.cdma_code=cdma_code
		self.frames=frames

	# Send data corresponding to index of frame list
	def sendData(self,index):

		if(self.frames[index]=='i'): # Meaning idle
			data=0
		elif(self.frames[index]=='0'):
			data=-1
		else:
			data=1

		codeword=[data*self.cdma_code[i] for i in range(len(self.cdma_code))]
		print('Station '+str(self.stn_num)+' sending '+str(codeword))

		return codeword
