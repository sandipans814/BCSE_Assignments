class Sentence:
    def __init__(self, sent):
        self.words = set(sent.split())

    @classmethod
    def reverse(cls, sent):
        return cls(sent[::-1])

    def getWords(self):
        return self.words

    def palindrome(self, obj):
        return self.words.intersection(obj.words)


sentence = input("Enter a sentence : ").rstrip('.')
uniqueWords = Sentence(sentence)
palindromeWords = Sentence.reverse(sentence).palindrome(uniqueWords)
print("The unique words in the sentence are : " + str(uniqueWords.getWords()))
print("The palindrome words in the sentence are : " + str(palindromeWords))