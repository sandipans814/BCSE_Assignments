def main():
    usr_input = input("Enter 5 numbers : ")
    integers_list = list(map(int, usr_input.split()))
    print(sorted(integers_list, reverse=False))

if __name__=="__main__":
    main()