#!/usr/bin/env ruby

product = 1
numbers = []

# read numbers from stdin line by line
ARGF.each_line do |line|
  number = line.to_i
  # store in array
  numbers.push(number)
  # calculate running product
  product *= number
  # last?
  break if ARGF.eof?
end

# iterate numbers and print product without current number
numbers.each do |number|
  puts product / number
end
