#!/usr/bin/env python3

INF = 10**9
N, M = map(int, input().split())
last = -1
vis, counted = dict(), set()

for i in range(M):
    t, x = map(int, input().split())
    if t == 1:
        vis[x] = i
    elif t == 2:
        if not x in counted and vis[x] < last:
            counted.add(x)
        vis[x] = INF
    else:
        last = i

for x, vist in vis.items():
    if not x in counted and vist < last:
        counted.add(x)

for x in sorted(list(counted)):
    print(x)