#!/usr/bin/env python

import fileinput

numbers = []
product = 1

# read numbers line by line from stdin and insert into array
# and calculate running product
for line in fileinput.input():
    number = int(line)
    numbers.append(number)
    product *= number

# print products without own number iterating array
for number in numbers:
    print product / number
