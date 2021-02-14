class Book:
    def __init__(self, title, cat, year):
        self.title = title
        self.category = cat
        self.year = year

    def changeTitle(self):
        self.title = input("Enter new title : ")


class EBook(Book):
    def __init__(self, title, year, pages):
        super().__init__(title, "EBook", year)
        self.pages = pages

    def changePageCount(self):
        self.pages = input("Enter new page count : ")


class Journal(Book):
    def __init__(self, title, year, publisher):
        super().__init__(title, "Journal", year)
        self.publisher = publisher

    def changePageCount(self):
        self.publisher = input("Enter new page count : ")


category = int(input("Enter the category of book (1 - EBook, 2 - Journal) : "))
if category == 1:
    t = input("Enter title of the e-book : ")
    y = input("Enter year of publishing of the e-book : ")
    p = input("Enter publisher of the e-book : ")
    obj = EBook(t, y, p)
elif category == 2:
    t = input("Enter title of the journal : ")
    y = input("Enter year of publishing of the journal : ")
    cnt = input("Enter page count of the journal : ")
    obj = EBook(t, y, cnt)
else:
    print("Wrong Choice !!")