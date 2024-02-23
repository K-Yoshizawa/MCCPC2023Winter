#include <iostream>
#include "testlib.h"
#include "constraints.hpp"
using namespace std;

const int NOISE_MAX = 3;
const int NOISE_MIN = 0;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    // サンプル
    vector<array<int,4>> sample_inputs;
    sample_inputs.push_back({1,1,2,2});
    sample_inputs.push_back({0,2,0,0});
    for(int t = 0; t < sample_inputs.size(); t++){
        ofstream of(format("00_sample_%02d.in", t + 1).c_str());
        auto [sx, sy, gx, gy] = sample_inputs[t];
        of << sx << ' ' << sy << ' ' << gx << ' ' << gy << '\n';
        of.close();
    }

    // 部分点(sx = sy = 0 かつ 0 <= gx,gy <= 2)
    for (int gx = 0; gx <= 2; gx++) {
        for (int gy = 0; gy <= 2; gy++){
            ofstream of(format("01_subtask_%02d.in", gx*3 + gy + 1).c_str());
            int sx = 0, sy = 0;
            of << sx << ' ' << sy << ' ' << gx << ' ' << gy << '\n';
            of.close();
        }
    }
    
    //ランダム
    for (int t = 0; t < 15; t++) {
        ofstream of(format("02_random_%02d.in", t + 1).c_str());
        int sx = rnd.next(MIN_SX, MAX_SX);
        int sy = rnd.next(MIN_SY, MAX_SY);
        int gx = rnd.next(MIN_GX, MAX_GX);
        int gy = rnd.next(MIN_GY, MAX_GY);
        of << sx << ' ' << sy << ' ' << gx << ' ' << gy << '\n';
        of.close();
    }

    //極端な値を入力
    for(int bit = 0; bit < (1 << 4); bit++){
        array<int, 4> input_value;
        for(int i = 0; i < 4; i++){
            int noise = rnd.next(NOISE_MIN, NOISE_MAX);

            //sx == gx かつ sy == gy のケースを入れたいので bit == 0 だけノイズを載せない
            if(bit == 0) noise = 0;

            bool maxflag = (bit >> i) & 1;
            input_value[i] = (maxflag ? MAX_VAL - noise : MIN_VAL + noise);
        }

        ofstream of(format("03_hand_%02d.in", bit + 1).c_str());
        auto [sx, sy, gx, gy] = input_value;
        of << sx << ' ' << sy << ' ' << gx << ' ' << gy << '\n';
        of.close();
    }

    return 0;
}
