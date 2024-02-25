#!/usr/bin/env python3

import math
N, M = map(int, input().split())

# 0 以上 N 未満の M の倍数は 1 + floor((N-1)/M) 個あるので、確率は (1 + floor((N-1)/M))/N 
numer = 1 + (N-1)//M    #分子
denom = N               #分母

# 既約分数で表すために、分子と分母を最大公約数で割る
g = math.gcd(numer, denom)
numer //= g
denom //= g

print(numer, denom)
