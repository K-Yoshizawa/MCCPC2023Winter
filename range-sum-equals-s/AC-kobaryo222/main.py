#!/usr/bin/env python3

MOD = 998244353

N, M, S = map(int, input().split())

ans = 1
for i in range(1, M):
    ans = (ans * (S - i) * pow(i, MOD - 2, MOD)) % MOD

print(ans)