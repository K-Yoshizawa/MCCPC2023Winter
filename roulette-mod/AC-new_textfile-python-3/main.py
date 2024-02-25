#!/usr/bin/env python3

# 2 つの非負整数 a, b の最大公約数を返す関数
def gcd(a, b):
    if b == 0 : return a
    return gcd(b, a%b)

def solve(N, M):
    
    # 0 以上 N 未満の M の倍数は 1 + floor((N-1)/M) 個あるので、確率は (1 + floor((N-1)/M))/N 
    numer = 1 + (N-1)//M    #分子
    denom = N               #分母

    # 既約分数で表すために、分子と分母を最大公約数で割る
    g = gcd(numer, denom)
    numer //= g
    denom //= g

    print(numer, denom)


T = int(input())

for i in range(T):
    N, M = map(int, input().split())
    solve(N, M)
