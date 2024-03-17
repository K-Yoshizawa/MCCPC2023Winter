#!/usr/bin/env python3

N = int(input())
X, Y, Z = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

# 1. A が大きい順にソート -> 条件を満たすまで勉強
# 2. B が大きい順にソート -> 条件を満たすまで勉強
# 3. C が大きい順にソート -> 条件を満たすまで勉強

ans = [-1] * N
a, b, c = 0, 0, 0

for ai, i in sorted([(A[i], i) for i in range(N)])[::-1]:
    if a >= X:
        break
    a += ai
    ans[i] = 0

for bi, i in sorted([(B[i], i) for i in range(N)])[::-1]:
    if b >= Y:
        break
    if ans[i] != -1:
        continue
    b += bi
    ans[i] = 1

for ci, i in sorted([(C[i], i) for i in range(N)])[::-1]:
    if c >= Z:
        break
    if ans[i] != -1:
        continue
    c += ci
    ans[i] = 2

if a < X or b < Y or c < Z:
    print(-1)
    exit(0)

for i in range(N):
    if ans[i] == -1:
        ans[i] = 0

print(' '.join(map(str, ans)))