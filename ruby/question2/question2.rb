#!/usr/bin/env ruby

class Frequency
  def initialize
    @terms = {}
  end

  def add(term)
    if @terms[term]
      @terms[term] += 1
    else
      @terms[term] = 1
    end
  end

  def top(k)
    a = @terms.to_a

    # sort decending by value
    a.sort! { |x,y| y[1] <=> x[1] }

    a.each do |key, value|
      puts "#{key}"
      k -= 1
      break if k == 0
    end
  end
end

freq = Frequency.new

count = ARGF.readline.to_i

count.times do
  term = ARGF.readline.gsub!("\n", "")
  freq.add(term)

  exit 1 if ARGF.eof?
end

k = ARGF.readline.to_i

freq.top(k)
