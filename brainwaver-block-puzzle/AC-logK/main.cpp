#include <bits/stdc++.h>
using namespace std;

int main(){
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    int gap_x = (gx - sx + 400002) % 4;
    string S;
    switch(gap_x){
        case 0 : break;
        case 1 : S += "URDL"; break;
        case 2 : S += "UULDDR"; break;
        case 3 : S += "ULDR"; break;
    }
    int dx = abs(gx - sx), rev_x = gx < sx;
    for(int i = 0; i < dx; ++i){
        S += (rev_x ? "L" : "R");
    }

    int gap_y = (gy - sy + 400000) % 4;
    switch(gap_y){
        case 0 : break;
        case 1 : S += "RULD"; break;
        case 2 : S += "RRULLD"; break;
        case 3 : S += "RDLU"; break;
    }
    int dy = abs(gy - sy), rev_y = gy < sy;
    for(int i = 0; i < dy; ++i){
        S += (rev_y ? "D" : "U");
    }
    cout << S.size() << endl;
    cout << S << endl;
}