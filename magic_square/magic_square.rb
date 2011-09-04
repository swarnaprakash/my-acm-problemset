#!/usr/bin/ruby
# Author: Swarnaprakash
test_cases = gets.to_i

test_cases.times do
  n = gets.to_i
  puts n*(n*n+1)/2
end
