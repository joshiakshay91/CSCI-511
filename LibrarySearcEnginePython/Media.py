from __future__ import print_function


class Media(object):

    def __init__(self, callnumber, title, subject, notes):
        self.callnumber = callnumber
        self.title = title
        self.subject = subject
        self.notes = notes

    def searchtitle(self, title):
        return title in self.title

    def searchcalln(self, callnumber):
        return callnumber in self.callnumber

    def searchsubject(self, subject):
        return subject in self.subject

    def display(self):
        print(" Title: " + self.title)
        print(" Call Number: "+self.callnumber)
        print(" Subject: " + self.subject)
        print(" Notes: " + self.notes)