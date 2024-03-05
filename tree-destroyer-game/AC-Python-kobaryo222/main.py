#!/usr/bin/env python3

from collections import deque

N = int(input())
G = [[] for i in range(N)]
for i in range(N - 1):
    A, B = map(int, input().split())
    A, B = A - 1, B - 1
    G[A].append(B)
    G[B].append(A)

T = [[] for i in range(N)]
que = deque()
que.append((0, -1))

while len(que) != 0:
    v, p = que.popleft()
    for u in G[v]:
        if u == p:
            continue
        T[v].append(u)
        que.append((u, v))

x = list(map(int, input().split()))
used = [False] * N

def bfs(v):
    que = deque()
    que.append((v, -1))
    ret = 0
    while len(que) != 0:
        u, p = que.popleft()
        if used[u]:
            continue
        used[u] = True
        ret += 1
        for w in T[u]:
            if w == p:
                continue
            que.append((w, u))
    return ret

ans = 0
for i in range(N - 1):
    ans += bfs(x[i] - 1)**2

print(ans)