#include <iostream>
#include <cassert>
#include "testlib.h"
#include "constraints.hpp"
using namespace std;

typedef long long int ll;

const ll MIN_M_SMALL = 1;
const ll MAX_M_SMALL = 100;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    // サンプル
    vector<array<ll,2>> sample_inputs;
    sample_inputs.push_back({6, 100});
    for(int t = 0; t < sample_inputs.size(); t++){
        ofstream of(format("00_sample_%02d.in", t + 1).c_str());
        auto [N, M] = sample_inputs[t];
        of << N << ' ' << M << '\n';
        of.close();
    }

    //ランダム(Mが小さいケース)
    for (int t = 0; t < 10; t++){
        ofstream of(format("01_random_%02d.in", t + 1).c_str());
        ll N = rnd.next(MIN_N, MAX_N);
        ll M = rnd.next(MIN_M_SMALL, MAX_M_SMALL);
        of << N << ' ' << M << '\n';
        of.close();
    }
    
    //ランダム
    for (int t = 0; t < 15; t++) {
        ofstream of(format("02_random_%02d.in", t + 1).c_str());
        ll N = rnd.next(MIN_N, MAX_N);
        ll M = rnd.next(MIN_M, MAX_M);
        of << N << ' ' << M << '\n';
        of.close();
    }

    //コーナーになりそうなケース
    vector<array<ll,2>> hand_inputs;
    
    // N = M の場合
    {
        ll N = rnd.next(MIN_N, MAX_N);
        hand_inputs.push_back({N, N});
        hand_inputs.push_back({MAX_N, MAX_M}); //極端なケース
    }

    // N mod M = -1, 0, 1 の場合
    for(int t = 0; t < 5; t++){
        ll M = rnd.next(2ll, MAX_N-1);
        ll N = rnd.next(1ll, (MAX_N-1)/M) * M;
        assert(1 <= N-1 && N+1 <= MAX_N);
        hand_inputs.push_back({N-1, M});
        hand_inputs.push_back({N, M});
        hand_inputs.push_back({N+1, M});
    }

    // M = 1 の場合(確率1)
    {
        for(int t = 0; t < 5; t++){
            ll N = rnd.next(MIN_N, MAX_N);
            hand_inputs.push_back({N, 1});
        }
        hand_inputs.push_back({MAX_N, 1}); //極端なケース
    }

    // N < M の場合
    {
        ll N = rnd.next(MIN_N, MAX_N/2);
        ll M = rnd.next(N+1, MAX_M);
        hand_inputs.push_back({N,M});
        hand_inputs.push_back({1, MAX_M}); //極端なケース        
    }
    
    //15ケース
    for(int t = 0; t < hand_inputs.size(); t++){
        ofstream of(format("02_hand_%02d.in", t + 1).c_str());
        auto [N, M] = hand_inputs[t];
        of << N << ' ' << M << '\n';
        of.close();
    }
    
    return 0;
}
