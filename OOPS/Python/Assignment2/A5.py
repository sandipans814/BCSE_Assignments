class Square:
    def __init__(self, side):
        self.__side = side

    def Area(self):
        return self.__side ** 2


s = int(input("Enter side : "))
sq = Square(s)
print("Area : {}".format(sq.Area()))
