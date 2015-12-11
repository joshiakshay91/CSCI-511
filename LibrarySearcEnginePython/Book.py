from Media import Media


class Book(Media):
    def __init__(self, callnumber, title, subject, author, description, publisher, city, year, series, notes):
        super(Book, self).__init__(callnumber, title, subject, notes)
        self.author = author
        self.description = description
        self.publisher = publisher
        self.city = city
        self.year = year
        self.series = series

    def searchother(self, other):
        return other in self.description or other in self.year

    def display(self):
        print("--------------------BOOK--------------------")
        super(Book, self).display()
        print(" Author: " + self.author)
        print(" Description: " + self.description)
        print(" Publisher: " + self.publisher)
        print(" City: " + self.city)
        print(" Year: " + self.year)
        print("Series:" + self.series)
        print("--------------------------------------------\n")
