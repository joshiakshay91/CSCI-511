import sys
import os
from Engine import Engine

engSearch = Engine()

digit = 0
keyword = 0
print("Hello")
while int(digit) != 5:
    print("\n--------------------MENU--------------------")
    print("Please Enter A valid numeric option for searching")
    print("1.Search by Call Number")
    print("2.Search by Title")
    print("3.Search by Subject")
    print("4.Search by Other Fields")
    print("5.Quit")
    while True:
        try:
            digit = int(raw_input("Enter Your Numeric Input:")) #if checking from python shell put input
        except ValueError:
            print("Sorry I understand only Numbers :(")
            continue
        else:
            break
    if int(digit) == 1:
        keyword = raw_input("Input for search by call Number: ")
        result = engSearch.searchcn(keyword)
    elif int(digit) == 2:
        keyword = raw_input("Input for search by title: ")
        engSearch.searchti(keyword)
    elif int(digit) == 3:
        keyword = raw_input("Input for search by Subject Name: ")
        engSearch.searchsub(keyword)
    elif int(digit) == 4:
        keyword = raw_input("Input for search by other: ")
        engSearch.searchoth(keyword)
    elif int(digit) == 5:
        break
    if int(digit) > 5 or int(digit) < 1:
        print("Invalid Option selected please enter again")
exit()
