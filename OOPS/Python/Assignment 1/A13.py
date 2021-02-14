def get_dictionary_containing_case_swapped_ascii_values(name):
    
    dictionary = {}
    characters = list(name)

    for ch in characters:
        if ch in dictionary:
            continue
        if ch.isupper():
            ch_case_swapped = ch.lower()
        else:
            ch_case_swapped = ch.upper()
        dictionary[ch] = ord(ch_case_swapped)

    return dictionary

def main():
    
    str_input = input("Enter your name : ").rstrip()
    print(get_dictionary_containing_case_swapped_ascii_values(str_input))


if __name__=="__main__":
    main()