#!/usr/bin/env python3
N, D = map(int, input().split())
S = input()
idx = S.find('0')
if idx == -1:
    idx = N
ans = S[:idx] + '1' * (D - N) + S[idx:]
print(ans)