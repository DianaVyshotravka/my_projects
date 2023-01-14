#Data on n=10 students of the class are given:
# surname, first name, patronymic, date of birth (year, month number, number).
# Write a program that determines whether there are students in the class
# whose birthday is today, and if so,
# then display their first and last names on the screen.

import datetime


def birthday():
    person = {}
    s = []
    d = str(datetime.date.today()).replace("-", ".")
    for i in range(0, 6, 2):
        s.append(input("Enter the date of birth(year, month,day):")) #birth
        s.append(input("Enter the full name:")) #name
        if s[i] == d and s[i] in person:
            person[s[i]].append(s[i+1])
        else:
            person[s[i]] = [s[i+1]]
    if d in person:
        print("who have birthday today:")
        for k in person[d]:
            print(k)
    else:
        print("Nobody has birthday today")


birthday()

