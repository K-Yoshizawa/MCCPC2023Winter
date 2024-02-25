#!/usr/bin/env python3
from fractions import Fraction

def solve(N, M):
    ans = Fraction(1 + (N-1)//M, N)
    print(ans.numerator, ans.denominator)


T = int(input())

for i in range(T):
    N, M = map(int, input().split())
    solve(N, M)
