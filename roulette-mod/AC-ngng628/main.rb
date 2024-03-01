#!/usr/bin/env ruby

gets.to_i.times do
  n, m = gets.split.map &:to_i
  ans = Rational(0.step(to: n - 1, by: m).size, n)
  puts "#{ans.numerator} #{ans.denominator}"
end
