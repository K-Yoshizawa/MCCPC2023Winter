#include "testlib.h"
#include "constraints.hpp"
#include <bits/stdc++.h>
#include <string>
using namespace std;

struct Dice{
    vector<int> num;
    int top,north,south,west,east,bottom;

    Dice(){
        top = 0, south = 1, east = 2, west = 3, north = 4, bottom = 5;
        num = vector<int>({1,2,3,4,5,6});
    }
    
    void roll(char dir){
        int temp;
        switch(dir){
            case 'U':
                temp = south; south = bottom; bottom = north; north = top; top = temp;
                break;
            case 'R':
                temp = west; west = bottom; bottom = east; east = top; top = temp;
                break;
            case 'D':
                temp = north; north = bottom; bottom = south; south = top; top = temp;
                break;
            case 'L':
                temp = east; east = bottom; bottom = west; west = top; top = temp;
                break;
        }
    };

    int get_bottom(){
        return num[bottom];
    }
};

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    //入力
    int sx = inf.readInt(MIN_SX, MAX_SX); inf.readSpace();
    int sy = inf.readInt(MIN_SY, MAX_SY); inf.readSpace();
    int gx = inf.readInt(MIN_GX, MAX_GX); inf.readSpace();
    int gy = inf.readInt(MIN_GY, MAX_GY);

    //解答
    int N_out = ouf.readInt(ANS_MIN_LENGTH, ANS_MAX_LENGTH); ouf.readEoln();
    string S_out = ouf.readToken(format("[LRUD]{%d, %d}", ANS_MIN_LENGTH, ANS_MAX_LENGTH));
    
    // N != |S| の場合 WA
    if(S_out.size() != N_out){
        quitf(_wa, "Wrong Answer");
        return 0;
    }
    
    Dice dice;
    dice.num = vector<int>({1,2,3,4,5,6});
    int x = sx, y = sy;
    
    for(auto c : S_out){
        dice.roll(c);

        if(c == 'U') y++;
        else if(c == 'D') y--;
        else if(c == 'R') x++;
        else if(c == 'L') x--;
    }
       
    // 操作後の座標が (gx, gy) であり, 最初に上面だった面が底面になっていれば AC
    if(x == gx && y == gy && dice.get_bottom() == 1){
        quitf(_ok, "Accepted");
    }
    else{
        quitf(_wa, "Wrong Answer");
    }

    return 0;
}
