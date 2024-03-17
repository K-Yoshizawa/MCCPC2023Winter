#!/usr/bin/env python3

N = int(input())
X, Y, Z = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

dp = [[[-1 for _ in range(Y + 1)] for _ in range(X + 1)] for _ in range(N + 1)]
pre = [[[(-1, -1, -1, -1) for _ in range(Y + 1)] for _ in range(X + 1)] for _ in range(N + 1)]
dp[0][0][0] = 0

for i in range(N):
    for x in range(X + 1):
        for y in range(Y + 1):
            if dp[i][x][y] == -1:
                continue
            if dp[i + 1][min(x + A[i], X)][y] < dp[i][x][y]:
                pre[i + 1][min(x + A[i], X)][y] = (i, x, y, 0)
                dp[i + 1][min(x + A[i], X)][y] = dp[i][x][y]
            if dp[i + 1][x][min(y + B[i], Y)] < dp[i][x][y]:
                pre[i + 1][x][min(y + B[i], Y)] = (i, x, y, 1)
                dp[i + 1][x][min(y + B[i], Y)] = dp[i][x][y]
            if dp[i + 1][x][y] < dp[i][x][y] + C[i]:
                pre[i + 1][x][y] = (i, x, y, 2)
                dp[i + 1][x][y] = dp[i][x][y] + C[i]

if dp[N][X][Y] < Z:
    print(-1)
    exit()

ans = []
cur = (N, X, Y)

for i in range(N, 0, -1):
    i, X, Y = cur
    ans.append(pre[i][X][Y][3])
    cur = pre[i][X][Y][:3]

print(' '.join(map(str, ans[::-1])))