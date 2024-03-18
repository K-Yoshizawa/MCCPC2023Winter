#!/usr/bin/env python3
from decimal import Decimal
from fractions import Fraction

def solve(N, M):

    #一旦小数を経由
    ans = Fraction(Decimal((1 + (N-1)//M)/N)).limit_denominator(N)
    print(ans.numerator, ans.denominator)


T = int(input())

for i in range(T):
    N, M = map(int, input().split())
    solve(N, M)
