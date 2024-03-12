#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

// 制約用
const int MIN_N = 1;
const int MAX_SUB_N = 3000;
const int MAX_N = 300000;
const int MIN_M = 1;
const int MAX_SUB_M = 3000;
const int MAX_M = 300000;

// ケース生成用
const int MIN_SUB_SMALL_N = 300;
const int MAX_SUB_SMALL_N = 600;
const int MIN_SUB_LARGE_N = 2700;
const int MAX_SUB_LARGE_N = 3000;
const int MIN_MAIN_SMALL_N = 30000;
const int MAX_MAIN_SMALL_N = 60000;
const int MIN_MAIN_LARGE_N = 270000;
const int MAX_MAIN_LARGE_N = 300000;
const int MIN_SUB_SMALL_M = 300;
const int MAX_SUB_SMALL_M = 600;
const int MIN_SUB_LARGE_M = 2700;
const int MAX_SUB_LARGE_M = 3000;
const int MIN_MAIN_SMALL_M = 30000;
const int MAX_MAIN_SMALL_M = 60000;
const int MIN_MAIN_LARGE_M = 270000;
const int MAX_MAIN_LARGE_M = 300000;

void make_random_case(string case_name, int N, int M){
    ofstream of(case_name.c_str());
    of << N << " " << M << endl;
    vector<int> vis, unvis;
    for(int i = 1; i <= N; ++i) unvis.push_back(i);
    for(int i = 0; i < M; ++i){
        int t;
        while(1){
            t = rnd.next(1, 3);
            if(t == 1 and unvis.empty()) continue;
            if(t == 2 and vis.empty()) continue;
            break;
        }
        int x;
        if(t == 1){
            int sel = rnd.next(0, (int)unvis.size() - 1);
            x = unvis[sel];
            unvis.erase(unvis.begin() + sel);
            vis.push_back(x);
        }
        if(t == 2){
            int sel = rnd.next(0, (int)vis.size() - 1);
            x = vis[sel];
            vis.erase(vis.begin() + sel);
            unvis.push_back(x);
        }
        if(t == 3) x = 0;
        of << t << " " << x << endl;
    }
    of.close();
}

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);

    // sample
    {
        ofstream of(format("00_sample_01.in").c_str());
        of << "3 6" << endl;
        of << "1 1" << endl;
        of << "1 2" << endl;
        of << "2 1" << endl;
        of << "3 0" << endl;
        of << "1 3" << endl;
        of << "3 0" << endl;
        of.close();
    }
    {
        ofstream of(format("00_sample_02.in").c_str());
        of << "3 7" << endl;
        of << "1 1" << endl;
        of << "1 3" << endl;
        of << "2 3" << endl;
        of << "2 1" << endl;
        of << "3 0" << endl;
        of << "1 1" << endl;
        of << "1 3" << endl;
        of.close();
    }

    // subtask
    {
        // small random
        for(int i = 0; i < 5; ++i){
            make_random_case(format("11_small_random_%02d.in", i + 1), rnd.next(MIN_SUB_SMALL_N, MAX_SUB_SMALL_N), rnd.next(MIN_SUB_SMALL_M, MAX_SUB_SMALL_M));
        }
        // large random
        for(int i = 0; i < 5; ++i){
            make_random_case(format("12_large_random_%02d.in", i + 1), rnd.next(MIN_SUB_LARGE_N, MAX_SUB_LARGE_N), rnd.next(MIN_SUB_LARGE_M, MAX_SUB_LARGE_M));
        }
        // max random
        for(int i = 0; i < 5; ++i){
            make_random_case(format("13_max_random_%02d.in", i + 1), rnd.next(MAX_SUB_N, MAX_SUB_N), rnd.next(MAX_SUB_M, MAX_SUB_M));
        }
        // hand case
        {
            ofstream of(format("14_hand_01.in").c_str());
            of << "1 1" << endl;
            of << "1 1" << endl;
            of.close();
        }
        {
            ofstream of(format("14_hand_02.in").c_str());
            of << "3000 3000" << endl;
            for(int j = 1; j <= 3000; ++j) of << "1 " << j << endl;
            of.close();
        }
        {
            ofstream of(format("14_hand_03.in").c_str());
            of << "2999 3000" << endl;
            for(int j = 1; j <= 2999; ++j) of << "1 " << j << endl;
            of << "3 0" << endl;
            of.close();
        }
    }

    // maintask
    {
        // small random
        for(int i = 0; i < 5; ++i){
            make_random_case(format("21_small_random_%02d.in", i + 1), rnd.next(MIN_MAIN_SMALL_N, MAX_MAIN_SMALL_N), rnd.next(MIN_MAIN_SMALL_M, MAX_MAIN_SMALL_M));
        }
        // large random
        for(int i = 0; i < 5; ++i){
            make_random_case(format("22_large_random_%02d.in", i + 1), rnd.next(MIN_MAIN_LARGE_N, MAX_MAIN_LARGE_N), rnd.next(MIN_MAIN_LARGE_M, MAX_MAIN_LARGE_M));
        }
        // max random
        for(int i = 0; i < 5; ++i){
            make_random_case(format("23_max_random_%02d.in", i + 1), rnd.next(MAX_N, MAX_N), rnd.next(MAX_M, MAX_M));
        }
        // hand case
        {
            ofstream of(format("24_hand_01.in").c_str());
            of << "300000 300000" << endl;
            for(int j = 1; j <= 300000; ++j) of << "1 " << j << endl;
            of.close();
        }
        {
            ofstream of(format("24_hand_02.in").c_str());
            of << "299999 300000" << endl;
            for(int j = 1; j <= 299999; ++j) of << "1 " << j << endl;
            of << "3 0" << endl;
            of.close();
        }
        {
            ofstream of(format("24_hand_03.in").c_str());
            of << "150000 300000" << endl;
            for(int j = 1; j <= 150000; ++j) of << "1 " << j << endl;
            for(int j = 1; j <= 150000; ++j) of << "2 " << j << endl;
            of.close();
        }
    }

    return 0;
}