#!/usr/bin/env python3

sx, sy, gx, gy = map(int, input().split())
dir = {c : c for c in "LRUD"}

# sx > gx のとき、グリッドを左右反転してから sx <= gx の場合と同様の処理を行う
if sx > gx :
    sx *= -1
    gx *= -1
    dir['L'], dir['R'] = 'R', 'L'
    
# sy > gy のとき、グリッドを上下反転してから sy <= gy の場合と同様の処理を行う
if sy > gy : 
    sy *= -1
    gy *= -1
    dir['U'], dir['D'] = 'D', 'U'

S = ""
while (gy-sy) % 4 != 2:
    sy -= 1
    S += dir['R'] + dir['D'] + dir['L']

S += dir['U']*((gy-1)-sy) + dir['R']*(gx-sx) + dir['U']
N = len(S)

print(N)
print(S)
