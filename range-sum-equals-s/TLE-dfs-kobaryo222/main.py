#!/usr/bin/env python3

MOD = 998244353

N, M, S = map(int, input().split())

# 長さ m, 総和が s である数列が何通りあるか
def dfs(m: int, s: int) -> int:
    if s <= 0:
        return 0
    if m == 1:
        return 1
    ret = 0
    for i in range(1, s):
        ret = (ret + dfs(m - 1, s - i)) % MOD
    return ret

print(dfs(M, S))