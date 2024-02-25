#!/usr/bin/env python3

from decimal import Decimal
from fractions import Fraction
N, M = map(int, input().split())

#一旦小数を経由
ans = Fraction(Decimal((1 + (N-1)//M)/N)).limit_denominator(N)
print(ans.numerator, ans.denominator)
