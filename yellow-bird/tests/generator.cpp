#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MIN_N = 1;
const int MAX_N = 300000;
const int MIN_M = 1;
const int MAX_M = 300000;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    for(int i = 0; i < 5; ++i){
        ofstream of(format("22_random_%02d.in", i + 1).c_str());
        int N = rnd.next(MIN_N, MAX_N), M = rnd.next(MIN_M, MAX_M);
        of << N << " " << M << endl;
        vector<int> vis, unvis;
        for(int j = 1; j <= N; ++j) unvis.push_back(j);
        for(int j = 0; j < M; ++j){
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
    return 0;
}