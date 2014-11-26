#!/usr/bin/env python

import fileinput
import sys

class circular_buffer:
    def __init__(self, size):
        self.buffer = [None] * size
        self.head = 0
        self.tail = 0
        self.lastWasAdd = False

    def add(self, value):
        self.buffer[self.head] = value
        if self.head == self.tail and self.lastWasAdd:
            self.head = (self.head + 1) % len(self.buffer)
            self.tail = self.tail
        else:
            self.head = (self.head + 1) % len(self.buffer)
        self.lastWasAdd = True

    def remove(self, count):
        for _ in xrange(count):
            self.tail = (self.tail + 1) % len(self.buffer)
            if self.tail == self.head:
                break
        self.lastWasAdd = False

    def list(self):
        if self.empty():
            return
        pos = self.tail
        while True:
            print self.buffer[pos]
            pos = (pos + 1) % len(self.buffer)
            if pos == self.head:
                break

    def empty(self):
        return self.head == self.tail and not lastWasAdd

# read size of buffer from stdin
size = int(sys.stdin.readline())

buffer = circular_buffer(size)

# read command from stdin
while True:
    command = sys.stdin.read(1)

    if command == 'A':
        count = int(sys.stdin.readline())
        for _ in xrange(count):
            line = sys.stdin.readline().rstrip('\n')
            buffer.add(line)
    elif command == 'R':
        count = int(sys.stdin.readline())
        buffer.remove(count)
    elif command == 'L':
        buffer.list()
        sys.stdin.readline() # discard the newline
    elif command == 'Q':
        sys.exit(0)
    else:
        sys.exit(1)
