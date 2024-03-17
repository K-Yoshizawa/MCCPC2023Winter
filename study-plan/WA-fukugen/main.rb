#!/usr/bin/env ruby

n = gets.to_i
x, y, z = gets.split.map &:to_i
a = gets.split.map &:to_i
b = gets.split.map &:to_i
c = gets.split.map &:to_i

INF = 10**18
xx = x + a.max
yy = y + b.max
dp = Array.new(n + 1) { Array.new(xx + 1) { [-INF] * (yy + 1) } }
dp[0][0][0] = 0
route = Array.new(n + 1) { Array.new(xx + 1) { [[-1, -1]] * (yy + 1) } }
n.times do |i|
  from = dp[i]
  to = dp[i + 1]
  (0..xx).each do |ma|
    (0..yy).each do |ph|
      # Study Math
      if ma >= a[i] && to[ma][ph] < from[ma - a[i]][ph]
        to[ma][ph] = from[ma - a[i]][ph]
        route[i + 1][ma][ph] = [ma - a[i], ph]
      end

      # Study Physics
      if ph >= b[i] && to[ma][ph] < from[ma][ph - b[i]]
        to[ma][ph] = from[ma][ph - b[i]]
        route[i + 1][ma][ph] = [ma, ph - b[i]]
      end

      # Study English
      if to[ma][ph] < from[ma][ph] + c[i]
        to[ma][ph] = from[ma][ph] + c[i]
        route[i + 1][ma][ph] = [ma, ph]
      end
    end
  end
end

(x..xx).each do |xxx|
  (y..yy).each do |yyy|
    if dp.last[xxx][yyy] >= z
      ans = []
      day = n
      ma, ph = xxx, yyy
      until day == 0
        ma2, ph2 = route[day][ma][ph]
        if ma2 == ma && ph2 == ph
          ans << 2
        elsif ma2 < ma
          ans << 0
        else
          ans << 1
        end
        ma, ph = ma2, ph2
        day -= 1
      end
      puts ans.reverse.join ' '
      exit
    end
  end
end

puts -1
