#!/usr/bin/env python3

n, m = map(int, input().split())
s = set()
closed = set()
for _ in range(m):
   t, x = map(int, input().split())
   if x in closed:
      continue
   if t == 1:
      s.add(x)
   elif t == 2:
      s.remove(x)
   else:
      for elem in s:
         closed.add(elem)

      s = set()

ans = list(map(str, sorted(list(closed))))
print(len(ans))

