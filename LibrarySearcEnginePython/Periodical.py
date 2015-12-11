from Media import Media


class Periodical(Media):

    def __init__(self, callnumber, title, subject, author, description, publisher, publishinghist, series, notes, relatedtitles, oformstitle, govtdoc):
        super(Periodical, self).__init__(callnumber, title, subject, notes)
        self.author = author
        self.description = description
        self.publisher = publisher
        self.publishinghist = publishinghist
        self.series = series
        self.relatedtitles = relatedtitles
        self.oformstitle = oformstitle
        self.govtdoc = govtdoc

    def searchother(self, other):
        return other in self.description or other in self.series or other in self.relatedtitles

    def display(self):
        print("----------------PERIODICALS-----------------")
        super(Periodical, self).display()
        print(" Author: " + self.author)
        print(" Description: " + self.description)
        print(" Publisher: " + self.publisher)
        print(" Publishing History: " + self.publishinghist)
        print(" Series: " + self.series)
        print(" Related Titles: " + self.relatedtitles)
        print(" Other Forms: " + self.oformstitle)
        print(" Govt. Doc. Number: " + self.govtdoc)