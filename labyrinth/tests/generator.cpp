#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

// 制約用
const int MIN_N = 2;
const int MAX_N = 700;

// ケース生成用
const int MIN_SMALL_N = 70;
const int MAX_SMALL_N = 140;
const int MIN_LARGE_N = 630;
const int MAX_LARGE_N = 700;

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};
const string D = "LRUD";

void subtask_gen(string case_name, int N){
    ofstream of(case_name.c_str());
    int M = 2 * (N * N - 1);
    of << N << " " << M << endl;
    vector<vector<int>> L(N, vector<int>(N, 0));
    bool cont = true;
    auto check = [&](int y, int x) -> bool {
        if(y < 0 or y >= N or x < 0 or x >= N) return false;
        return true;
    };
    auto dfs = [&](auto self, int y, int x, int n) -> void {
        if(!cont) return;
        L[y][x] = n;
        if(y == N - 1 and x == N - 1){
            if(n == N * N) cont = false;
            if(cont) L[y][x] = 0;
            return;
        }
        array<int, 4> direction{0, 1, 2, 3};
        shuffle(direction.begin(), direction.end());
        for(auto d : direction){
            if(!cont) return;
            int ny = y + dy[d], nx = x + dx[d];
            if(check(ny, nx) and L[ny][nx] == 0){
                self(self, ny, nx, n + 1);
            }
        }
        if(cont) L[y][x] = 0;
    };
    dfs(dfs, 0, 0, 1);
    string S;
    int y = 0, x = 0;
    for(int c = 1; c < N * N; ++c){
        for(int d = 0; d < 4; ++d){
            int ny = y + dy[d], nx = x + dx[d];
            if(check(ny, nx) and L[ny][nx] == c + 1){
                S.push_back(D[d]);
                S.push_back(D[d]);
                y = ny, x = nx;
                break;
            }
        }
    }
    of << S << endl;
    of.close();
}

struct UnionFind {
    vector< int > data;

    UnionFind() = default;

    explicit UnionFind(size_t sz) : data(sz, -1) {}

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int find(int k) {
        if(data[k] < 0) return (k);
        return data[k] = find(data[k]);
    }

    int size(int k) {
        return -data[find(k)];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    vector< vector< int > > groups() {
        int n = (int) data.size();
        vector< vector< int > > ret(n);
        for(int i = 0; i < n; i++) {
            ret[find(i)].emplace_back(i);
        }
        ret.erase(remove_if(begin(ret), end(ret), [&](const vector< int > &v) {
            return v.empty();
        }), end(ret));
        return ret;
    }
};

void main_gen(string case_name, int N, int mode = 0){
    ofstream of(case_name.c_str());
    vector<pair<int, int>> vs;
    for(int i = 0; i < N * N; ++i){
        if((i + 1) % N != 0){
            vs.push_back({i, i + 1});
        }
        if(i + N < N * N){
            vs.push_back({i, i + N});
        }
    }
    shuffle(vs.begin(), vs.end());
    UnionFind uf(N * N);
    int n = 2 * N + 1;
    vector<vector<int>> L(n, vector<int>(n, 0));
    for(int i = 1; i < n; i += 2){
        for(int j = 1; j < n; j += 2){
            L[i][j] = 1;
        }
    }
    auto conv = [&](int c) -> pair<int, int> {
        return {(c / N) * 2 + 1, (c % N) * 2 + 1};
    };
    while(!uf.same(0, N * N - 1)){
        auto [a, b] = vs.back(); vs.pop_back();
        if(!uf.unite(a, b)) continue;
        auto [ay, ax] = conv(a);
        auto [by, bx] = conv(b);
        L[(ay + by) / 2][(ax + bx) / 2] = 1;
    }
    string S, TS;
    auto dfs = [&](auto self, int y, int x) -> void {
        if(y == n - 2 and x == n - 2){
            S = TS;
            return;
        }
        L[y][x] = 2;
        for(int d = 0; d < 4; ++d){
            int ny = y + dy[d], nx = x + dx[d];
            if(L[ny][nx] == 1){
                TS.push_back(D[d]);
                self(self, ny, nx);
                TS.pop_back();
            }
        }
        L[y][x] = 1;
    };
    dfs(dfs, 1, 1);

    if(mode == 1){
        int m = rnd.next(0, (int)S.size());
        S.erase(S.begin() + m);
    }
    if(mode == 2){
        int rem = 2 * N * N - S.size();
        int m = rnd.next(1, rem / 2) * 2;
        auto p = rnd.perm((int)S.size() / 2);
        int a = min(p[0], p[1]) * 2, b = max(p[0], p[1]) * 2;
        string T;
        if(a != 0) T += S.substr(0, a);
        array<int, 4> direction{0, 1, 2, 3};
        shuffle(direction.begin(), direction.end());
        for(auto d : direction){
            if(d == 0){
                if(a != 0 and S[a - 1] == 'R') continue;
                if(S[b] == 'R') continue;
            }
            if(d == 1){
                if(a != 0 and S[a - 1] == 'L') continue;
                if(S[b] == 'L') continue;
            }
            if(d == 2){
                if(a != 0 and S[a - 1] == 'D') continue;
                if(S[b] == 'D') continue;
            }
            if(d == 3){
                if(a != 0 and S[a - 1] == 'U') continue;
                if(S[b] == 'U') continue;
            }
            T += string(m, D[d]);
            break;
        }
        T += S.substr(b);
        S = T;
    }
    if(mode == 3){
        int rem = 2 * N * N - S.size();
        int m = rnd.next(1, rem / 2) * 2;
        auto p = rnd.perm((int)S.size() / 2);
        array<int, 4> direction{0, 1, 2, 3};
        shuffle(direction.begin(), direction.end());
        for(auto d : direction){
            if(d == 0 and S.back() == 'R') continue;
            if(d == 1 and S.back() == 'L') continue;
            if(d == 2 and S.back() == 'D') continue;
            if(d == 3 and S.back() == 'U') continue;
            S += string(m, D[d]);
            break;
        }
    }

    of << N << " " << S.size() << endl;
    of << S << endl;
    of.close();
}

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);

    // sample
    {
        ofstream of(::format("00_sample_01.in").c_str());
        of << "3 8" << endl;
        of << "RRDDRRDD" << endl;
        of.close();
    }
    {
        ofstream of(::format("00_sample_02.in").c_str());
        of << "3 6" << endl;
        of << "RRRRUU" << endl;
        of.close();
    }
    {
        ofstream of(::format("00_sample_03.in").c_str());
        of << "3 16" << endl;
        of << "DDDDRRUUUURRDDDD" << endl;
        of.close();
    }
    {
        ofstream of(::format("00_sample_04.in").c_str());
        of << "3 14" << endl;
        of << "RRDDLLDDRRRRUU" << endl;
        of.close();
    }

    // subtask
    {
        // N = 3
        {
            ofstream of(::format("11_n3_01.in").c_str());
            of << "3 16" << endl;
            of << "RRRRDDLLLLDDRRRR" << endl;
            of.close();
        }
        {
            ofstream of(::format("11_n3_02.in").c_str());
            of << "3 16" << endl;
            of << "DDDDRRUUUURRDDDD" << endl;
            of.close();
        }
        // N = 5
        for(int i = 0; i < 10; ++i){
            subtask_gen(::format("12_n5_%02d.in", i + 1).c_str(), 5);
        }
    }

    // main
    {
        // Yes N = 2
        {
            ofstream of(::format("21_min_01.in").c_str());
            of << "2 4" << endl;
            of << "RRDD" << endl;
            of.close();
        }
        {
            ofstream of(::format("21_min_02.in").c_str());
            of << "2 4" << endl;
            of << "DDRR" << endl;
            of.close();
        }
        // Yes small
        for(int i = 0; i < 5; ++i){
            main_gen(::format("22_small_%02d.in", i + 1).c_str(), rnd.next(MIN_SMALL_N, MAX_SMALL_N));
        }
        // Yes large
        for(int i = 0; i < 5; ++i){
            main_gen(::format("23_large_%02d.in", i + 1).c_str(), rnd.next(MIN_LARGE_N, MAX_LARGE_N));
        }
        // Yes max
        for(int i = 0; i < 20; ++i){
            main_gen(::format("24_max_%02d.in", i + 1).c_str(), rnd.next(MAX_N, MAX_N));
        }
        // Yes shortest
        {
            ofstream of(::format("25_shortest_01.in").c_str());
            of << "700 2796" << endl;
            for(int i = 0; i < MAX_N - 1; ++i) of << "RR";
            for(int i = 0; i < MAX_N - 1; ++i) of << "DD";
            of << endl;
            of.close();
        }
        {
            ofstream of(::format("25_shortest_02.in").c_str());
            of << "700 2796" << endl;
            for(int i = 0; i < MAX_N - 1; ++i) of << "DD";
            for(int i = 0; i < MAX_N - 1; ++i) of << "RR";
            of << endl;
            of.close();
        }
        // Yes longest
        {
            ofstream of(::format("26_longest_01.in").c_str());
            of << "699 977200" << endl;
            for(int i = 0; i < MAX_N - 1; ++i){
                for(int j = 0; j < MAX_N - 2; ++j){
                    if(i % 2) of << "LL";
                    else of << "RR";
                }
                if(i != MAX_N - 2) of << "DD";
            }
            of << endl;
            of.close();
        }
        {
            ofstream of(::format("26_longest_02.in").c_str());
            of << "699 977200" << endl;
            for(int i = 0; i < MAX_N - 1; ++i){
                for(int j = 0; j < MAX_N - 2; ++j){
                    if(i % 2) of << "UU";
                    else of << "DD";
                }
                if(i != MAX_N - 2) of << "RR";
            }
            of << endl;
            of.close();
        }
        // No 1
        for(int i = 0; i < 3; ++i){
            main_gen(::format("31_ng_%02d.in", i + 1).c_str(), rnd.next(MIN_N, MAX_N), 1);
        }
        // No 2
        for(int i = 0; i < 3; ++i){
            main_gen(::format("32_ng_%02d.in", i + 1).c_str(), rnd.next(MIN_N, MAX_N), 2);
        }
        // No 3
        for(int i = 0; i < 3; ++i){
            main_gen(::format("33_ng_%02d.in", i + 1).c_str(), rnd.next(MIN_N, MAX_N), 3);
        }
        // No 4
        {
            ofstream of(::format("34_ng_01.in").c_str());
            of << "2 12" << endl;
            of << "RRDDLLUURRDD" << endl;
            of.close();
        }
        {
            ofstream of(::format("34_ng_02.in").c_str());
            of << "2 12" << endl;
            of << "DDRRUULLDDRR" << endl;
            of.close();
        }
    }
}