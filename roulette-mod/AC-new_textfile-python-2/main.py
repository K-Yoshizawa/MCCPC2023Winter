#!/usr/bin/env python3

from fractions import Fraction
N, M = map(int, input().split())

ans = Fraction(1 + (N-1)//M, N)
print(ans.numerator, ans.denominator)
