#!/usr/bin/env python3
import sys

sys.setrecursionlimit(10000000)

MOD = 998244353

N, M, S = map(int, input().split())
dp = [[-1] * (S + 1) for _ in range(M + 1)]

# 長さ m, 総和が s である数列が何通りあるか
def dfs(m: int, s: int) -> int:
    if s <= 0:
        return 0
    if m == 1:
        return 1
    if dp[m][s] != -1:
        return dp[m][s]
    ret = 0
    for i in range(1, s):
        ret = (ret + dfs(m - 1, s - i)) % MOD
    dp[m][s] = ret
    return ret

print(dfs(M, S))