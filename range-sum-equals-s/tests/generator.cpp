#include "testlib.h"
#include "bits/stdc++.h"
#include "constraints.hpp"

using namespace std;

void gen(string name, int N, int M, int S)
{
    ofstream ofs(name);
    ofs << N << " " << M << " " << S << endl;
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    // sample
    {
        gen("00_sample_01.in", 3, 2, 4);
        gen("00_sample_02.in", 5, 4, 3);
        gen("00_sample_03.in", 1'000'000'000, 100'000, 987654321);
    }
    // subtask
    {
        // random
        for (int i = 0; i < 10; i++) {
            int N = rnd.next(MIN_N, MAX_N_SUBTASK);
            int M = rnd.next(MIN_M, min(N, MAX_M_SUBTASK));
            int S = rnd.next(MIN_S, MAX_S_SUBTASK);
            gen(format("10_subtask_random_%02d.in", i + 1).c_str(), N, M, S);
        }
        for (int i = 0; i < 5; i++) {
            // S < M として答えが 0 になるケースを作る
            int N = rnd.next(MIN_N, MAX_N_SUBTASK);
            int M = rnd.next(MIN_M + 1, min(N, MAX_M_SUBTASK));
            int S = rnd.next(MIN_S, min(MAX_S_SUBTASK, M - 1));
            gen(format("11_subtask_random_%02d.in", i + 1).c_str(), N, M, S);
        }
        // hand
        gen("12_subtask_hand_01.in", 1, 1, 1);
        gen("12_subtask_hand_02.in", 100, 50, 100);
        gen("12_subtask_hand_03.in", 100, 100, 100);
    }
    // random
    {
        for (int i = 0; i < 10; i++) {
            int N = rnd.next(MIN_N, MAX_N);
            int M = rnd.next(MIN_M, min(N, MAX_M));
            int S = rnd.next(MIN_S, MAX_S);
            gen(format("20_random_%02d.in", i + 1).c_str(), N, M, S);
        }
    }
    // hand
    {
        gen("30_hand_01.in", MAX_N, MAX_M, 998244353);
        gen("30_hand_02.in", MAX_N, MAX_M, 998244354);
    }
    return 0;
}