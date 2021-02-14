from collections import Counter


def findLen(string):
    counter = 0
    for i in string:
        counter += 1
    return counter


def len(string) -> list:
    length = []
    total = 0
    count = Counter()
    for word in string.split():
        if count.get(word) is None:
            count[word] = 1
            total += 1
        else:
            count[word] += 1
    for word, cnt in count.most_common(total):
        if cnt == 1:
            break
        length.append((word, findLen(word)))
    return length


print(len(input("Enter a sentence : ")))