from Book import Book
from Video import Video
from Periodical import Periodical
from Film import Film


class Engine(object):
    data = []

    def __init__(self):

        self.populatelibraydata("book.txt")
        self.populatelibraydata("periodic.txt")
        self.populatelibraydata("film.txt")
        self.populatelibraydata("video.txt")

    def populatelibraydata(self, key):
        global chunk
        filein = open(key, 'r')
        for line in filein:
            item = line.strip().split('|')
            if key == 'book.txt':
                chunk = Book(*item)
            if key == 'periodic.txt':
                chunk = Periodical(*item)
            if key == 'film.txt':
                chunk = Film(*item)
            if key == 'video.txt':
                chunk = Video(*item)
            self.data.append(chunk)
        filein.close()

    def searchcn(self, keyword):
        tempresults = []
        for chunk in self.data:
            if chunk.searchcalln(keyword):
                tempresults.append(chunk)
        for result in tempresults:
            result.display()

    def searchti(self, keyword):
        tempresults = []
        for chunk in self.data:
            if chunk.searchtitle(keyword):
                tempresults.append(chunk)
        for result in tempresults:
            result.display()

    def searchsub(self, keyword):
        tempresults = []
        for chunk in self.data:
            if chunk.searchsubject(keyword):
                tempresults.append(chunk)
        for result in tempresults:
            result.display()

    def searchoth(self, keyword):
        tempresults = []
        for chunk in self.data:
            if chunk.searchother(keyword):
                tempresults.append(chunk)
        for result in tempresults:
            result.display()
