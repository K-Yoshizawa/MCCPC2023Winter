#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

// 制約用
const int MIN_N = 1;
const int MAX_SUB_N = 3000;
const int MAX_N = 200000;

// ケース生成用
const int RATIO_MIN_SMALL = 1;
const int RATIO_MAX_SMALL = 2;
const int RATIO_MIN_LARGE = 9;
const int RATIO_MAX_LARGE = 10;
const int MIN_SUB_SMALL_N = MAX_SUB_N * RATIO_MIN_SMALL / 10;
const int MAX_SUB_SMALL_N = MAX_SUB_N * RATIO_MAX_SMALL / 10;
const int MIN_SUB_LARGE_N = MAX_SUB_N * RATIO_MIN_LARGE / 10;
const int MAX_SUB_LARGE_N = MAX_SUB_N * RATIO_MAX_LARGE / 10;
const int MIN_MAIN_SMALL_N = MAX_N * RATIO_MIN_SMALL / 10;
const int MAX_MAIN_SMALL_N = MAX_N * RATIO_MAX_SMALL / 10;
const int MIN_MAIN_LARGE_N = MAX_N * RATIO_MIN_LARGE / 10;
const int MAX_MAIN_LARGE_N = MAX_N * RATIO_MAX_LARGE / 10;

struct UnionFind {
    vector< int > data;

    UnionFind(int sz) {
        data.assign(sz, -1);
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return (false);
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }

    int find(int k) {
        if(data[k] < 0) return (k);
        return (data[k] = find(data[k]));
    }

    int size(int k) {
        return (-data[find(k)]);
    }
};

vector<pair<int, int>> make_tree(int N){
    vector<pair<int, int>> ret;
    UnionFind uf(N + 1);
    while(ret.size() < N - 1){
        int A, B;
        auto p = rnd.distinct(2, N);
        A = p[0] + 1, B = p[1] + 1;
        if(A > B) swap(A, B);
        if(!uf.unite(A, B)) continue;
        ret.push_back({A, B});
    }
    return ret;
}

void make_random_case(string case_name, int N){
    ofstream of(case_name.c_str());
    of << N << endl;
    for(auto [A, B] : make_tree(N)){
        of << A << " " << B << endl;
    }
    auto x = rnd.perm(N);
    for(int i = 0; i < N; ++i){
        of << x[i] + 1 << (i + 1 == N ? '\n' : ' ');
    }
    of.close();
    return;
}

void make_vicious_case(string case_name, int N){
    ofstream of(case_name.c_str());
    of << N << endl;
    auto T = make_tree(N);
    vector<vector<int>> G(N + 1);
    for(auto [A, B] : T){
        of << A << " " << B << endl;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    vector<int> x;
    queue<pair<int, int>> que;
    que.push({1, 0});
    while(que.size()){
        auto [v, p] = que.front(); que.pop();
        if(v != 1) x.push_back(v);
        for(auto u : G[v]){
            if(u == p) continue;
            que.push({u, v});
        }
    }
    reverse(x.begin(), x.end());
    for(int i = 0; i < N; ++i){
        of << x[i] << (i + 1 == N ? '\n' : ' ');
    }
    of.close();
    return;
}

void make_random_case_path(string case_name, int N){
    ofstream of(case_name.c_str());
    of << N << endl;
    for(int i = 1; i < N; ++i){
        of << i << " " << i + 1 << endl;
    }
    auto x = rnd.perm(N);
    for(int i = 0; i < N; ++i){
        of << x[i] + 1 << (i + 1 == N ? '\n' : ' ');
    }
    of.close();
    return;
}

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);

    // sample
    {
        ofstream of(format("00_sample_01.in").c_str());
        of << "5" << endl;
        of << "1 2" << endl;
        of << "1 3" << endl;
        of << "2 4" << endl;
        of << "2 5" << endl;
        of << "4 2 5 3" << endl;
        of.close();
    }
    {
        ofstream of(format("00_sample_02.in").c_str());
        of << "5" << endl;
        of << "1 2" << endl;
        of << "2 3" << endl;
        of << "3 4" << endl;
        of << "4 5" << endl;
        of << "4 2 5 3" << endl;
        of.close();
    }
    {
        ofstream of(format("00_sample_03.in").c_str());
        of << "8" << endl;
        of << "1 2" << endl;
        of << "2 3" << endl;
        of << "2 4" << endl;
        of << "3 5" << endl;
        of << "3 6" << endl;
        of << "4 7" << endl;
        of << "4 8" << endl;
        of << "2 8 7 6 5 4 3" << endl;
        of.close();
    }

    // easy
    {
        // small
        for(int i = 1; i <= 5; ++i){
            make_random_case_path(format("11_small_%02d.in", i), rnd.next(MIN_SUB_SMALL_N, MAX_SUB_SMALL_N));
        }
        // large
        for(int i = 1; i <= 5; ++i){
            make_random_case_path(format("12_large_%02d.in", i), rnd.next(MIN_SUB_LARGE_N, MAX_SUB_LARGE_N));
        }
        // max
        for(int i = 1; i <= 5; ++i){
            make_random_case_path(format("13_max_%02d.in", i), rnd.next(MAX_SUB_N, MAX_SUB_N));
        }
    }

    // normal
    {
        // small
        for(int i = 1; i <= 5; ++i){
            make_random_case(format("21_small_%02d.in", i), rnd.next(MIN_SUB_SMALL_N, MAX_SUB_SMALL_N));
        }
        // large
        for(int i = 1; i <= 5; ++i){
            make_random_case(format("22_large_%02d.in", i), rnd.next(MIN_SUB_LARGE_N, MAX_SUB_LARGE_N));
        }
        // max
        for(int i = 1; i <= 5; ++i){
            make_random_case(format("23_max_%02d.in", i), rnd.next(MAX_SUB_N, MAX_SUB_N));
        }
        for(int i = 6; i <= 10; ++i){
            make_vicious_case(format("23_max_%02d.in", i), rnd.next(MAX_SUB_N, MAX_SUB_N));
        }
        // hand
        {
            ofstream of(format("24_hand_01.in").c_str());
            of << MAX_SUB_N << endl;
            for(int i = 1; i < MAX_SUB_N; ++i){
                of << i << " " << i + 1 << endl;
            }
            for(int i = MAX_SUB_N; i >= 2; --i){
                of << i << (i == 2 ? "\n" : " ");
            }
            of.close();
        }
        {
            ofstream of(format("24_hand_02.in").c_str());
            of << MAX_SUB_N << endl;
            for(int i = 1; i < MAX_SUB_N; ++i){
                of << i << " " << i + 1 << endl;
            }
            for(int i = 2; i <= MAX_SUB_N; ++i){
                of << i << (i == MAX_SUB_N ? "\n" : " ");
            }
            of.close();
        }
    }

    // hard
    {
        // small
        for(int i = 1; i <= 5; ++i){
            make_random_case(format("31_small_%02d.in", i), rnd.next(MIN_MAIN_SMALL_N, MAX_MAIN_SMALL_N));
        }
        // large
        for(int i = 1; i <= 5; ++i){
            make_random_case(format("32_large_%02d.in", i), rnd.next(MIN_MAIN_LARGE_N, MAX_MAIN_LARGE_N));
        }
        // max
        for(int i = 1; i <= 5; ++i){
            make_random_case(format("33_max_%02d.in", i), rnd.next(MAX_N, MAX_N));
        }
        for(int i = 6; i <= 10; ++i){
            make_vicious_case(format("33_max_%02d.in", i), rnd.next(MAX_N, MAX_N));
        }
        // hand
        {
            ofstream of(format("34_hand_01.in").c_str());
            of << MAX_N << endl;
            for(int i = 1; i < MAX_N; ++i){
                of << i << " " << i + 1 << endl;
            }
            for(int i = MAX_N; i >= 2; --i){
                of << i << (i == 2 ? "\n" : " ");
            }
            of.close();
        }
        {
            ofstream of(format("34_hand_02.in").c_str());
            of << MAX_N << endl;
            for(int i = 1; i < MAX_N; ++i){
                of << i << " " << i + 1 << endl;
            }
            for(int i = 2; i <= MAX_N; ++i){
                of << i << (i == MAX_N ? "\n" : " ");
            }
            of.close();
        }
    }
}