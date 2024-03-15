#!/usr/bin/env python3

INF = 1e9
N, M = map(int, input().split())

last = -1
vis, counted = [INF] * (N + 1), [False] * (N + 1)

for i in range(M):
    t, x = map(int, input().split())
    if t == 1:
        vis[x] = i
    elif t == 2:
        if not counted[x] and vis[x] < last:
            counted[x] = True
        vis[x] = INF
    else:
        last = i

for i in range(1, N + 1):
    if not counted[i] and vis[i] < last:
        counted[i] = True

for i in range(1, N + 1):
    if counted[i]:
        print(i)