#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

// 制約用
const int EASY_N = 3000;
const int NORMAL_N = 300000;
const int HARD_N = 1000000000;
const int EASY_M = 3000;
const int NORMAL_M = 300000;
const int HARD_M = 300000;

// ケース生成用
const double MIN_SMALL = 0.10;
const double MAX_SMALL = 0.20;
const double MIN_LARGE = 0.90;
const double MAX_LARGE = 1.00;

void make_random_case(string case_name, int N, int M){
    ofstream of(case_name.c_str());
    of << N << " " << M << endl;
    vector<int> vis, unvis;
    if(N <= NORMAL_N){
        for(int i = 1; i <= N; ++i) unvis.push_back(i);
    }
    else{
        set<int> selected;
        for(int i = 0; i < M; ++i){
            while(1){
                int x = rnd.next(1, N);
                if(selected.count(x)) continue;
                selected.insert(x);
                unvis.push_back(x);
                break;
            }
        }
    }
    for(int i = 0; i < M; ++i){
        int t = -1;
        while(t == -1){
            switch(rnd.next(1, 5)){
                case 1 :
                case 2 :
                    if(unvis.empty()) break;
                    t = 1;
                    break;
                case 3 :
                case 4 :
                    if(vis.empty()) break;
                    t = 2;
                    break;
                case 5 :
                    t = 3;
                    break;
            }
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

    // EASY
    {
        // small random
        for(int i = 0; i < 3; ++i){
            make_random_case(format("11_small_random_%02d.in", i + 1),
                             rnd.next(EASY_N * MIN_SMALL, EASY_N * MAX_SMALL),
                             rnd.next(EASY_M * MIN_SMALL, EASY_M * MAX_SMALL));
        }
        // large random
        for(int i = 0; i < 3; ++i){
            make_random_case(format("12_large_random_%02d.in", i + 1),
                             rnd.next(EASY_N * MIN_LARGE, EASY_N * MAX_LARGE),
                             rnd.next(EASY_M * MIN_LARGE, EASY_M * MAX_LARGE));
        }
        // max random
        for(int i = 0; i < 3; ++i){
            make_random_case(format("13_max_random_%02d.in", i + 1), EASY_N, EASY_M);
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

    // NORMAL
    {
        // small random
        for(int i = 0; i < 3; ++i){
            make_random_case(format("21_small_random_%02d.in", i + 1),
                             rnd.next(NORMAL_N * MIN_SMALL, NORMAL_N * MAX_SMALL),
                             rnd.next(NORMAL_M * MIN_SMALL, NORMAL_M * MAX_SMALL));
        }
        // large random
        for(int i = 0; i < 3; ++i){
            make_random_case(format("22_large_random_%02d.in", i + 1),
                             rnd.next(NORMAL_N * MIN_LARGE, NORMAL_N * MAX_LARGE),
                             rnd.next(NORMAL_M * MIN_LARGE, NORMAL_M * MAX_LARGE));
        }
        // max random
        for(int i = 0; i < 3; ++i){
            make_random_case(format("23_max_random_%02d.in", i + 1), NORMAL_N, NORMAL_M);
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

    // HARD
    {
        // small random
        for(int i = 0; i < 5; ++i){
            make_random_case(format("31_small_random_%02d.in", i + 1),
                             rnd.next(HARD_N * MIN_SMALL, HARD_N * MAX_SMALL),
                             rnd.next(HARD_M * MIN_SMALL, HARD_M * MAX_SMALL));
        }
        // large random
        for(int i = 0; i < 5; ++i){
            make_random_case(format("32_large_random_%02d.in", i + 1),
                             rnd.next(HARD_N * MIN_LARGE, HARD_N * MAX_LARGE),
                             rnd.next(HARD_M * MIN_LARGE, HARD_M * MAX_LARGE));
        }
        // max random
        for(int i = 0; i < 5; ++i){
            make_random_case(format("33_max_random_%02d.in", i + 1), HARD_N, HARD_M);
        }
        // hand case
        {
            ofstream of(format("34_hand_01.in").c_str());
            of << "1000000000 300000" << endl;
            set<int> selected;
            for(int j = 1; j <= 300000; ++j){
                int x = rnd.next(1, HARD_N);
                while(selected.count(x)) x = rnd.next(1, HARD_N);
                selected.insert(x);
                of << "1 " << x << endl;
            }
            of.close();
        }
        {
            ofstream of(format("34_hand_02.in").c_str());
            of << "1000000000 300000" << endl;
            for(int j = 0; j < 300000; ++j) of << "1 " << 1000000000 - j << endl;
            of << "3 0" << endl;
            of.close();
        }
        {
            ofstream of(format("34_hand_03.in").c_str());
            of << "1000000000 300000" << endl;
            for(int j = 0; j < 150000; ++j) of << "1 " << 1000000000 - j << endl;
            for(int j = 0; j < 150000; ++j) of << "2 " << 1000000000 - j << endl;
            of.close();
        }
    }

    return 0;
}