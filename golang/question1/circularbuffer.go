package main

import(
	"fmt"
)

type circularBuffer struct {
	buffer []string
	head int
	tail int
	lastWasAdd bool
}

func CreateBuffer(size int) *circularBuffer {
	return &circularBuffer{ buffer: make([]string, size) }
}

func (b *circularBuffer) Add(value string) {
	b.buffer[b.head] = value
	// if buffer full, increment both head and tail
	if b.head == b.tail && b.lastWasAdd {
		b.tail = (b.tail + 1) % len(b.buffer)
		b.head = b.tail
	} else {
		b.head = (b.head + 1) % len(b.buffer)
	}
	b.lastWasAdd = true
}

func (b *circularBuffer) Remove(elements int) {
	// move tail lines steps or until equal head
	for elements > 0 && b.tail != b.head {
		b.tail = (b.tail + 1) % len(b.buffer)
		elements--
	}
	b.lastWasAdd = false
}

func (b *circularBuffer) List() {
	pos := b.tail
	for {
		fmt.Printf("%s\n", b.buffer[pos])
		pos = (pos + 1) % len(b.buffer)
		if pos == b.head {
			break
		}
	}
}

func (b *circularBuffer) Empty() bool {
	return b.head == b.tail && !b.lastWasAdd
}
