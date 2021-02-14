def main():
    lowercase_letters  = [chr(x) for x in range(ord('a'), ord('z') + 1)]
    enumerate_lowercase = {}

    for i, ch in enumerate(lowercase_letters):
        enumerate_lowercase[i + 1] = ch

    print(enumerate_lowercase)

if __name__=="__main__":
    main()