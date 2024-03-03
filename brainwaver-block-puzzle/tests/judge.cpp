#include "testlib.h"
#include "constraints.hpp"
#include <bits/stdc++.h>
#include <string>
//using namespace std;

typedef long long int ll;

struct Dice{
    std::vector<int> num;
    int top,north,south,west,east,bottom;

    Dice(){
        top = 0, south = 1, east = 2, west = 3, north = 4, bottom = 5;
        num = std::vector<int>({1,2,3,4,5,6});
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

const int ANS_MIN_N = 1;
const int ANS_MAX_N = 100'000;

const ll ANS_MIN_LENGTH = 1;
const ll ANS_MAX_LENGTH = 10'000'000'000ll;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    //入力
    ll sx = inf.readInt(MIN_SX, MAX_SX,"sx"); inf.readSpace(); 
    ll sy = inf.readInt(MIN_SY, MAX_SY,"sy"); inf.readSpace();
    ll gx = inf.readInt(MIN_GX, MAX_GX,"gx"); inf.readSpace();
    ll gy = inf.readInt(MIN_GY, MAX_GY,"gy"); 
    
    //解答
    ll N_out = ouf.readInt(ANS_MIN_N, ANS_MAX_N, "N_out"); ouf.readEoln();
    Dice dice;
    ll x = sx, y = sy;
    for(int i = 0; i < N_out; i++){
        std::string D = ouf.readToken("L|R|U|D", format("D_%d", i+1).c_str()); ouf.readSpace();
        ll L = ouf.readLong(ANS_MIN_LENGTH, ANS_MAX_LENGTH, format("L_%d", i+1).c_str()); ouf.readEoln();
        
        if(D == "L") x -= L;
        else if(D == "R") x += L;
        else if(D == "U") y += L;
        else if(D == "D") y -= L;

        for(int j = 0; j < (L % 4); j++) dice.roll(D.front());
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
