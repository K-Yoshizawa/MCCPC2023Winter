#!/usr/bin/env python3

n, d = map(int, input().split())
s = input()

if s == '0' * n:
   print('1' * (d - n) + s)
else:
   print(s + '1' * (d - n))
