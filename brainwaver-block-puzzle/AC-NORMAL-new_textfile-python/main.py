#!/usr/bin/env pypy3
from collections import deque

TOP=0
SOUTH=1
EAST=2
WEST=3
NORTH=4
BOTTOM=5

sx,sy,gx,gy = map(int, input().split())

minx = min(sx,gx)-2
maxx = max(sx,gx)+2
miny = min(sy,gy)-2
maxy = max(sy,gy)+2

prev = [[[(-1,-1,-1) for _ in range(6)] for _ in range(maxy-miny+1)] for _ in range(maxx-minx+1)]

que = deque()
prev[sx-minx][sy-miny][TOP] = (-2,-2,-2)
que.append((sx-minx,sy-miny,TOP));

while que:
    x,y,dir = que[0]
    que.popleft()

    #L
    nx, ny, ndir = x-1, y, dir
    if dir == TOP: ndir = WEST
    elif dir == EAST: ndir = TOP
    elif dir == WEST: ndir = BOTTOM
    elif dir == BOTTOM: ndir = EAST

    if 0 <= nx and nx < maxx-minx+1 and prev[nx][ny][ndir] == (-1,-1,-1):
        prev[nx][ny][ndir] = (x,y,dir);
        que.append((nx,ny,ndir))
    
    
    #R
    nx = x+1
    if dir == TOP: ndir = EAST
    elif dir == EAST: ndir = BOTTOM
    elif dir == WEST: ndir = TOP
    elif dir == BOTTOM: ndir = WEST

    if 0 <= nx and nx < maxx-minx+1 and prev[nx][ny][ndir] == (-1,-1,-1):
        prev[nx][ny][ndir] = (x,y,dir);
        que.append((nx,ny,ndir))
    

    #U
    nx, ny, ndir = x, y+1, dir
    if dir == TOP: ndir = NORTH
    elif dir == SOUTH: ndir = TOP
    elif dir == NORTH: ndir = BOTTOM
    elif dir == BOTTOM: ndir = SOUTH

    if 0 <= ny and ny < maxy-miny+1 and prev[nx][ny][ndir] == (-1,-1,-1):
        prev[nx][ny][ndir] = (x,y,dir);
        que.append((nx,ny,ndir))


    #D
    ny = y-1
    if dir == TOP: ndir = SOUTH
    elif dir == SOUTH: ndir = BOTTOM
    elif dir == NORTH: ndir = TOP
    elif dir == BOTTOM: ndir = NORTH

    if 0 <= ny and ny < maxy-miny+1 and prev[nx][ny][ndir] == (-1,-1,-1):
        prev[nx][ny][ndir] = (x,y,dir);
        que.append((nx,ny,ndir))


ans = []
x, y, dir = gx-minx, gy-miny, BOTTOM
t = prev[x][y][dir]

while t != (-2,-2,-2):
    prevx, prevy, prevdir = t
    dx, dy = x-prevx, y-prevy
    
    if dx == 1: ans.append(('R',1))
    elif dx == -1: ans.append(('L',1))
    elif dy == 1: ans.append(('U',1))
    elif dy == -1: ans.append(('D',1))

    x, y, dir = prevx, prevy, prevdir
    t = prev[x][y][dir]    

print(len(ans))

for d, l in ans:
    print(d,l)
