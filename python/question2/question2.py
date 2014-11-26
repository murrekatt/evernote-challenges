#!/usr/bin/env python

import fileinput
import sys
import operator

class frequency:
    def __init__(self):
        self.terms = dict()

    def add(self, term):
        if term in self.terms:
            self.terms[term] += 1
        else:
            self.terms[term] = 1

    def top(self, k):
        a = []
        # get terms into array
        for key in self.terms:
            a.append([key, self.terms[key]])
        # sort array pairs by value decending order
        a.sort(key = operator.itemgetter(1), reverse=True)
        # print k terms
        for term in a:
            print term[0]
            k -= 1
            if k == 0:
                break

freq = frequency()

n = int(sys.stdin.readline())

# read n terms line by line from stdin
for _ in xrange(n):
    term = sys.stdin.readline().rstrip('\n')
    freq.add(term)

k = int(sys.stdin.readline())

freq.top(k)
