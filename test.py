#! /usr/bin/python
# 014_1.py
import math
number = int(input("Enter a number: "))

list = []

def getChildren(num):
    print('*'*30)
    isZhishu = True
    i = 2
    square = int(math.sqrt(num)) + 1
    while i <= square:
        if num % i == 0:
            list.append(i)
            isZhishu = False
            getChildren(num / i)
            i += 1
            break
        i += 1
    if isZhishu:
        list.append(num)

getChildren(number)
print(list)