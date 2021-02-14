LINE_SIZE = 50
PAD_CHARACTER = '-'

def main():
    file = open("./14.txt", 'r')
    lines = file.readlines()
    file.close()

    total_string = ''.join(lines).replace('\n', ' ')
    words = total_string.split(' ')

    file = open("./14_2_Edited.txt", 'w')

    buffer = ""
    for word in words:
        temp_buffer = buffer + word + " "
        if len(temp_buffer) < LINE_SIZE:
            buffer = temp_buffer
        else:
            buffer += (LINE_SIZE - len(buffer)) * PAD_CHARACTER
            file.write(buffer + '\n')
            buffer = word + " "
    
    if len(buffer):
        file.write(buffer + '\n')

    file.close()


if __name__=="__main__":
    main()