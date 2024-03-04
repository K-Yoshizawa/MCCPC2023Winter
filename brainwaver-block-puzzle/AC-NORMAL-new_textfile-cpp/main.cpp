#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int TOP = 0;
const int SOUTH = 1;
const int EAST = 2;
const int WEST = 3;
const int NORTH = 4;
const int BOTTOM = 5;

int main(){
    ll sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    
    ll minx = min(sx,gx)-2, miny = min(sy,gy)-2, maxx = max(sx,gx)+2, maxy = max(sy,gy)+2;
    map<array<ll,3>, array<ll,3>> prev;
    queue<array<ll,3>> que;
    prev[{sx, sy, TOP}] = {-1,-1,-1};
    que.push({sx,sy,TOP});
    
    while(!que.empty()){
        auto [x,y,dir] = que.front();
        que.pop();

        ll ndir, nx, ny; 
        // L
        {
            nx = x-1, ny = y, ndir = dir;
            if(dir == TOP) ndir = WEST; 
            else if(dir == EAST) ndir = TOP;
            else if(dir == WEST) ndir = BOTTOM;
            else if(dir == BOTTOM) ndir = EAST;
            
            if(minx <= nx && nx <= maxx && prev.count({nx,ny,ndir}) == 0){
                prev[{nx,ny,ndir}] = {x,y,dir};
                que.push({nx,ny,ndir});
            }
        }

        // R
        {
            nx = x+1, ny = y, ndir = dir;
            if(dir == TOP) ndir = EAST;
            else if(dir == EAST) ndir = BOTTOM;
            else if(dir == WEST) ndir = TOP;
            else if(dir == BOTTOM) ndir = WEST;

            if(minx <= nx && nx <= maxx && prev.count({nx,ny,ndir}) == 0){
                prev[{nx,ny,ndir}] = {x,y,dir};
                que.push({nx,ny,ndir});
            }
        }
        
        // U
        {
            nx = x, ny = y+1, ndir = dir;
            if(dir == TOP) ndir = NORTH; 
            else if(dir == SOUTH) ndir = TOP;
            else if(dir == NORTH) ndir = BOTTOM;
            else if(dir == BOTTOM) ndir = SOUTH;
            
            if(miny <= ny && ny <= maxy && prev.count({nx,ny,ndir}) == 0){
                prev[{nx,ny,ndir}] = {x,y,dir};
                que.push({nx,ny,ndir});
            }
        } 

        // D
        {
            nx = x, ny = y-1, ndir = dir;
            if(dir == TOP) ndir = SOUTH;
            else if(dir == SOUTH) ndir = BOTTOM;
            else if(dir == NORTH) ndir = TOP;
            else if(dir == BOTTOM) ndir = NORTH;
            
            if(miny <= ny && ny <= maxy && prev.count({nx,ny,ndir}) == 0){
                prev[{nx,ny,ndir}] = {x,y,dir};
                que.push({nx,ny,ndir});
            }
        }
    }
    
    vector<pair<char,ll>> ans;

    ll x = gx, y = gy;
    for(array<ll,3> t = prev[{x,y,BOTTOM}]; t != array<ll,3>({-1,-1,-1}); t = prev[t]){
        ll dx = x-t[0], dy = y-t[1];
        
        if(dx == 1) ans.emplace_back('R', 1);
        else if(dx == -1) ans.emplace_back('L', 1);
        else if(dy == 1) ans.emplace_back('U', 1);
        else if(dy == -1) ans.emplace_back('D', 1);

        x = t[0], y = t[1];
    }
    reverse(ans.begin(), ans.end());
    
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        auto [d,l] = ans[i];
        cout << d << " " << l << endl;
    }
}
