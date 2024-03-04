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

ans = []
while (gy-sy) % 4 != 2:
    sy -= 1
    ans.append((dir['R'],1))
    ans.append((dir['D'],1))
    ans.append((dir['L'],1))

if (gy-1)-sy > 0:
    ans.append((dir['U'], (gy-1)-sy))

if (gx-sx) > 0:
    ans.append((dir['R'], (gx-sx)))


ans.append((dir['U'],1))

print(len(ans))
for D, L in ans:
    print(D, L)
