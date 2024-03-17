#!/usr/bin/env ruby

n = gets.to_i
x, y, z = gets.split.map &:to_i
a = gets.split.map &:to_i
b = gets.split.map &:to_i
c = gets.split.map &:to_i

INF = 10**18
dp = Array.new(n + 1) { Array.new(x + 1) { [-INF] * (y + 1) } }
dp[0][0][0] = 0
route = Array.new(n + 1) { Array.new(x + 1) { [[-1, -1, -1]] * (y + 1) } }
n.times do |i|
  from = dp[i]
  to = dp[i + 1]
  (0..x).each do |ma|
    (0..y).each do |ph|
      # Study Math
      if ma >= a[i] && to[ma][ph] < from[ma - a[i]][ph]
        to[ma][ph] = from[ma - a[i]][ph]
        route[i + 1][ma][ph] = [ma - a[i], ph, 0]
      end

      # Study Physics
      if ph >= b[i] && to[ma][ph] < from[ma][ph - b[i]]
        to[ma][ph] = from[ma][ph - b[i]]
        route[i + 1][ma][ph] = [ma, ph - b[i], 1]
      end

      # Study English
      if to[ma][ph] < from[ma][ph] + c[i]
        to[ma][ph] = from[ma][ph] + c[i]
        route[i + 1][ma][ph] = [ma, ph, 2]
      end
    end
  end
end

if dp.last.last.last >= z
  ans = []
  day = n
  ma, ph = x, y
  until day == 0
    ma2, ph2, t = route[day][ma][ph]
    ans << t
    ma, ph = ma2, ph2
    day -= 1
  end
  puts ans.reverse.join ' '
else
  puts -1
end
