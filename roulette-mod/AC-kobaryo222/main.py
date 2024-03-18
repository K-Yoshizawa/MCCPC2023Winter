#!/usr/bin/env python3

from math import gcd

T = int(input())
for i in range(T):
    N, M = map(int, input().split())
    a, b = (N - 1) // M + 1, N
    g = gcd(a, b)
    a, b = a // g, b // g
    print(a, b)
