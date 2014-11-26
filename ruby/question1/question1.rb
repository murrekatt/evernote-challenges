#!/usr/bin/env ruby

class CircularBuffer
  def initialize(size)
    @buffer = Array.new(size)
    @head = 0
    @tail = 0
    @lastWasAdd = false
  end

  def add(value)
    @buffer[@head] = value
    if @head == @tail && @lastWasAdd
      @head = (@head + 1) % @buffer.length
      @tail = @head
    else
      @head = (@head + 1) % @buffer.length
    end
    @lastWasAdd = true
  end

  def remove(count)
    return if empty?
    count.times do
      @tail = (@tail + 1) % @buffer.length
      break if @tail == @head
    end
    @lastWasAdd = false
  end

  def empty?
    @head == @tail && !@lastWasAdd
  end

  def list
    return if empty?
    pos = @tail
    loop do
      puts @buffer[pos]
      pos = (pos + 1) % @buffer.size
      break unless pos != @head
    end
  end
end

# read size of buffer
size = ARGF.readline.to_i

buffer = CircularBuffer.new(size)

loop do
  case ARGF.readchar
  when 'A'
    n = ARGF.readline.to_i
    # add n lines
    n.times do
      line = ARGF.readline
      buffer.add(line)
    end
  when 'R'
    n = ARGF.readline.to_i
    buffer.remove(n)
  when 'L'
    buffer.list
  when 'Q'
    exit 0
  else
    exit 1
  end
end

exit 2
