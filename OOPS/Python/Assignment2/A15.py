class Student:
    def __init__(self, name, score1, score2, score3):
        self.name = name
        self.score1 = score1
        self.score2 = score2
        self.score3 = score3

    def getName(self):
        return self.name

    def calcTotal(self):
        return self.score1 + self.score2 + self.score3


class MarkSheet:
    def __init__(self, students):
        self.results = {}
        for each in students:
            self.results[each] = each.calcTotal()

    def showRank(self):
        for ranker in sorted(self.results.items(), key=lambda kv: (kv[1], kv[0]), reverse=True):
            print(ranker[0].getName() + " : " + str(ranker[1]))


batch = []
while True:
    identity = input("Enter student name : ")
    marks = input("Enter marks in 3 subjects : ").split()
    batch.append(Student(identity, int(marks[0]), int(marks[1]), int(marks[2])))
    check = int(input("Do you want to add more students ? (1 -> Yes, 0 -> No) : "))
    if check == 0:
        break
markSheet = MarkSheet(batch)
markSheet.showRank()