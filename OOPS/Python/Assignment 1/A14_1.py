F = 65537

import random

def generate_hash(string, token_dict):
    if string in token_dict:
        return token_dict[string]

    characters = list(string)
    char_sum = 0
    for ch in characters:
        char_sum += ord(ch) * random.randint(0, 1e6)
    return char_sum % F

def main():
    file = open("./14.txt", 'r')
    lines = file.readlines()
    file.close()

    token_dict = {}

    for line in lines:
        line = line.replace('\n', '')
        words = line.split(' ')
        for word in words:
            hash = generate_hash(word, token_dict)
            token_dict[word] = hash
    
    print(token_dict)
    

if __name__=="__main__":
    main()