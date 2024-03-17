#!/usr/bin/env python3
N, D = map(int, input().split())
S = input()
ans = 0
for i in range(N + 1):
    t = int(S[:i] + '1' * (D - N) + S[i:])
    if ans < t:
        ans = t
print(ans)