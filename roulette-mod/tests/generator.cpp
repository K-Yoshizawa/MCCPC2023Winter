#include <iostream>
#include <cassert>
#include "testlib.h"
#include "constraints.hpp"
//using namespace std;

const int MIN_M_SMALL = 1;
const int MAX_M_SMALL = 100;

void output(std::vector<std::array<int,2>> &inputs, std::string filename){
    std::ofstream of(filename);

    of << inputs.size() << '\n';
    for(int i = 0; i < inputs.size(); i++){
        auto [N, M] = inputs[i];
        of << N << ' ' << M << '\n';
    }

    of.close();
}

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    // サンプル
    {
        std::vector<std::array<int,2>> sample_inputs;
        sample_inputs.push_back({6, 100});
        sample_inputs.push_back({6, 4});
        sample_inputs.push_back({1, 1000000000});
        output(sample_inputs, "00_sample_01.in");
    }

    //ランダム(Mが小さいケース)
    for (int i = 0; i < 2; i++){
        std::vector<std::array<int,2>> inputs;

        for(int t = 0; t < MAX_T; t++){
            int N = rnd.next(MIN_N, MAX_N);
            int M = rnd.next(MIN_M_SMALL, MAX_M_SMALL);
            inputs.push_back({N,M});
        }
        output(inputs, format("01_random_%02d.in", i + 1).c_str());
    }
    
    //ランダム
    for(int i = 0; i < 2; i++){
        std::vector<std::array<int,2>> inputs;

        for(int t = 0; t < MAX_T; t++){
            int N = rnd.next(MIN_N, MAX_N);
            int M = rnd.next(MIN_M, MAX_M);
            inputs.push_back({N,M});
        }
        output(inputs, format("02_random_%02d.in", i + 1).c_str());
    }

    //コーナーになりそうなケース
    {
        const int hand_case1 = 50;
        const int hand_case2 = 50;
        const int hand_case3 = 50;
        const int hand_case4 = 50;
        const int hand_case_rem = MAX_T - (hand_case1 + 3*hand_case2 + hand_case3 + hand_case4 + 50);

        std::vector<std::array<int,2>> hand_inputs;
        // N = M の場合
        for(int i = 0; i < hand_case1; i++){
            int N = rnd.next(MIN_N, MAX_N);
            hand_inputs.push_back({N, N});
        }
        hand_inputs.push_back({MAX_N, MAX_M}); //極端なケース
        
        // N mod M = -1, 0, 1 の場合
        for(int i = 0; i < hand_case2; i++){
            int M = rnd.next(2, MAX_N-1);
            int N = rnd.next(1, (MAX_N-1)/M) * M;
            assert(1 <= N-1 && N+1 <= MAX_N);
            hand_inputs.push_back({N-1, M});
            hand_inputs.push_back({N, M});
            hand_inputs.push_back({N+1, M});
        }
        
        // M = 1 の場合(確率1) 
        for(int i = 0; i < hand_case3 ; i++){
            int N = rnd.next(MIN_N, MAX_N);
            hand_inputs.push_back({N, 1});
        }
        hand_inputs.push_back({MAX_N, 1}); //極端なケース
        

        // N < M の場合
        for(int i = 0; i < hand_case4; i++){
            int N = rnd.next(MIN_N, MAX_N/2);
            int M = rnd.next(N+1, MAX_M);
            hand_inputs.push_back({N, M});
        }
        hand_inputs.push_back({1, MAX_M}); //極端なケース        
        
        
        // N が十分大きく、M が 2 以上 5 以下の場合(愚直をここで落とす)
        for(int i = 0; i < hand_case_rem; i++){
            int N = rnd.next(MAX_N - 100000, MAX_N);
            int M = rnd.next(2, 5);
            hand_inputs.push_back({N,M});
        }
        
        output(hand_inputs, "03_hand_01.in");
    }

    return 0;
}
