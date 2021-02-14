class String : 
    def __init__(self,text):
        self.text = text
    def __len__(self):
        length  = 0
        for item in self.text.split()[-3:]:
            length += len(item)
        return length
s = String(input("Enter a sentence : "))
print("Output from modified len : {}".format(len(s)))
