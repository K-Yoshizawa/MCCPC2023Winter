#!/usr/bin/env python3

N = int(input())
X, Y, Z = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))
dp = [[[-1 for _ in range(Y + 1)] for _ in range(X + 1)] for _ in range(N + 1)]
dp[0][0][0] = 0

for i in range(N):
    for x in range(X + 1):
        for y in range(Y + 1):
            if dp[i][x][y] == -1:
                continue
            dp[i + 1][min(x + A[i], X)][y] = max(dp[i + 1][min(x + A[i], X)][y], dp[i][x][y])
            dp[i + 1][x][min(y + B[i], Y)] = max(dp[i + 1][x][min(y + B[i], Y)], dp[i][x][y])
            dp[i + 1][x][y] = max(dp[i + 1][x][y], dp[i][x][y] + C[i])

if dp[N][X][Y] < Z:
    print(-1)
    exit()

ans = []
x, y, z = X, Y, Z
for i in range(N, 0, -1):
    if x - A[i - 1] >= 0 and dp[i][x][y] == dp[i - 1][x - A[i - 1]][y]:
        ans.append(0)
        x -= A[i - 1]
    elif y - B[i - 1] >= 0 and dp[i][x][y] == dp[i - 1][x][y - B[i - 1]]:
        ans.append(1)
        y -= B[i - 1]
    else:
        ans.append(2)
        z -= C[i - 1]

print(' '.join(map(str, ans[::-1])))