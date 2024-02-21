#!/usr/bin/env python3

N = int(input())
X, Y, Z = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))
dp = [[[[-1 for _ in range(Z + 1)] for _ in range(Y + 1)] for _ in range(X + 1)] for _ in range(N + 1)]
dp[0][0][0][0] = 0

for i in range(N):
    for x in range(X + 1):
        for y in range(Y + 1):
            for z in range(Z + 1):
                if dp[i][x][y][z] == -1:
                    continue
                dp[i + 1][min(x + A[i], X)][y][z] = 0
                dp[i + 1][x][min(y + B[i], Y)][z] = 1
                dp[i + 1][x][y][min(z + C[i], Z)] = 2

if dp[N][X][Y][Z] == -1:
    print(-1)
    exit()

ans = []
x, y, z = X, Y, Z
for i in range(N, 0, -1):
    ans.append(dp[i][x][y][z])
    if dp[i][x][y][z] == 0:
        x -= A[i - 1]
    elif dp[i][x][y][z] == 1:
        y -= B[i - 1]
    else:
        z -= C[i - 1]

print(' '.join(map(str, ans[::-1])))