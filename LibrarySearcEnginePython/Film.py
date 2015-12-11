from Media import Media


class Film(Media):

    def __init__(self, callnumber, title, subject, director, notes, year):
        super(Film, self).__init__(callnumber, title, subject, notes)
        self.director = director
        self.year = year

    def searchother(self, other):
        return other in self.director or other in self.notes or other in self.year

    def display(self):
        print(" --------------------FILM--------------------")
        super(Film, self).display()
        print(" Director: " + self.director)
        print(" Year: " + self.year)