def convert_to_words(num):

    output_string = ""
     
    # Get number of digits
    # in given number
    l = len(num) 
 
    # Base cases 
    if (l == 0):
        print("Empty String")
        return
 
    if (l > 4):
        print("Length more than 4 is not supported")
        return
 
    # The first string is not used, 
    # it is to make array indexing simple 
    single_digits = ["zero", "one", "two", "three", 
                     "four", "five", "six", "seven", 
                     "eight", "nine"]
 
    # The first string is not used, 
    # it is to make array indexing simple 
    two_digits = ["", "ten", "eleven", "twelve", 
                  "thirteen", "fourteen", "fifteen", 
                  "sixteen", "seventeen", "eighteen",
                  "nineteen"]
 
    # The first two string are not used,
    # they are to make array indexing simple
    tens_multiple = ["", "", "twenty", "thirty", "forty",
                     "fifty", "sixty", "seventy", "eighty", 
                     "ninety"]
 
    tens_power = ["hundred", "thousand"]
 
    # For single digit number 
    if (l == 1): 
        output_string += (single_digits[ord(num[0]) - '0'])
        return output_string
 
    # Iterate while num is not '\0' 
    x = 0
    while (x < len(num)): 
         
        # Code path for first 2 digits 
        if (l >= 3):
            if (ord(num[x]) - 48 != 0):
                output_string += (single_digits[ord(num[x]) - 48]) + " "
                output_string += (tens_power[l - 3]) + " " 
                # here len can be 3 or 4
                 
            l -= 1
             
        # Code path for last 2 digits
        else:
             
            # Need to explicitly handle 
            # 10-19. Sum of the two digits
            # is used as index of "two_digits"
            # array of strings 
            if (ord(num[x]) - 48 == 1): 
                sum = (ord(num[x]) - 48 +
                       ord(num[x+1]) - 48)
                output_string += (two_digits[sum])
                return output_string
 
            # Need to explicitely handle 20 
            elif (ord(num[x]) - 48 == 2 and
                  ord(num[x + 1]) - 48 == 0):
                output_string += ("twenty")
                return output_string
                 
            # Rest of the two digit 
            # numbers i.e., 21 to 99 
            else:
                i = ord(num[x]) - 48
                if(i > 0):
                    output_string += (tens_multiple[i]) + " "
                else:
                    output_string += ("") + " "
                x += 1
                if(ord(num[x]) - 48 != 0):
                    output_string += (single_digits[ord(num[x]) - 48])
        x += 1

        return output_string

def main():
    file = open("./15.txt", 'r')
    lines = file.readlines()
    file.close()

    file = open("./15_Edited.txt", 'w')

    for line in lines:
        words = line.replace('\n', '').rstrip().split(' ')
        buffer = ""
        for word in words:
            if word[0].isdigit():
                cnvt_word = convert_to_words(word)
                buffer += cnvt_word + " "
            else:
                buffer += word + " "
        buffer = buffer.rstrip()
        buffer = buffer[0].upper() + buffer[1:]
        file.write(buffer + '\n')

    file.close()



if __name__=="__main__":
    main()