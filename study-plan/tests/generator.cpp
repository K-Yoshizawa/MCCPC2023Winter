#include "testlib.h"
#include "bits/stdc++.h"
#include "constraints.hpp"

using namespace std;

void gen(string name, int N, int X, int Y, int Z, vector<int> A, vector<int> B, vector<int> C)
{
    ofstream ofs(name);
    ofs << N << endl;
    ofs << X << " " << Y << " " << Z << endl;
    for (int i = 0; i < N; i++) {
        if (i)
            ofs << " ";
        ofs << A[i];
    }
    ofs << endl;
    for (int i = 0; i < N; i++) {
        if (i)
            ofs << " ";
        ofs << B[i];
    }
    ofs << endl;
    for (int i = 0; i < N; i++) {
        if (i)
            ofs << " ";
        ofs << C[i];
    }
    ofs << endl;
}

template <class T>
bool chmin(T& a, const T& b) { return a > b ? a = b, true : false; }
template <class T>
bool chmax(T& a, const T& b) { return a < b ? a = b, true : false; }

bool check_ans_exists(int N, int X, int Y, int Z, vector<int>& A, vector<int>& B, vector<int>& C)
{
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(X + 1, vector<int>(Y + 1, 0)));
    for (int i = 0; i < N; i++) {
        for (int x = 0; x <= X; x++) {
            for (int y = 0; y <= Y; y++) {
                chmax(dp[i + 1][min(x + A[i], X)][y], dp[i][x][y]);
                chmax(dp[i + 1][x][min(y + B[i], Y)], dp[i][x][y]);
                chmax(dp[i + 1][x][y], dp[i][x][y] + C[i]);
            }
        }
    }
    return dp[N][X][Y] >= Z;
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    // sample
    {
        gen("00_sample_01.in", 5, 10, 20, 30,
            { 10, 0, 0, 0, 0 },
            { 0, 10, 10, 0, 0 },
            { 0, 0, 0, 10, 20 });
        gen("00_sample_02.in", 5, 100, 100, 100,
            { 10, 0, 0, 0, 0 },
            { 0, 10, 10, 0, 0 },
            { 0, 0, 0, 10, 20 });
    }
    // subtask
    {
        for (int i = 0; i < 10; i++) {
            int N = rnd.next(MIN_N, MAX_N_SUBTASK);
            int X = rnd.next(MIN_XYZ, MAX_XYZ_SUBTASK), Y = rnd.next(MIN_XYZ, MAX_XYZ_SUBTASK), Z = rnd.next(MIN_XYZ, MAX_XYZ_SUBTASK);
            vector<int> A(N), B(N), C(N);
            for (int j = 0; j < N; j++) {
                A[j] = rnd.next(MIN_ABC, MAX_ABC_SUBTASK);
                B[j] = rnd.next(MIN_ABC, MAX_ABC_SUBTASK);
                C[j] = rnd.next(MIN_ABC, MAX_ABC_SUBTASK);
            }
            gen(format("10_random_%02d.in", i + 1), N, X, Y, Z, A, B, C);
        }
        gen("11_hand_01.in", 10, 10, 10, 10,
            { 4, 4, 4, 2, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 1, 0, 3, 3, 3, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 3, 3, 4 });
    }
    // all
    {
        for (int i = 0; i < 10; i++) {
            int N = rnd.next(MIN_N, MAX_N_SUBTASK);
            int X = rnd.next(MIN_XYZ, MAX_XYZ), Y = rnd.next(MIN_XYZ, MAX_XYZ), Z = rnd.next(MIN_XYZ, MAX_XYZ);
            vector<int> A(N), B(N), C(N);
            for (int j = 0; j < N; j++) {
                A[j] = rnd.next(MIN_ABC, MAX_ABC);
                B[j] = rnd.next(MIN_ABC, MAX_ABC);
                C[j] = rnd.next(MIN_ABC, MAX_ABC);
            }
            gen(format("20_random_%02d.in", i + 1), N, X, Y, Z, A, B, C);
        }
        {
            // max
            int N = MAX_N;
            int X = MAX_XYZ, Y = MAX_XYZ, Z = MAX_XYZ;
            vector<int> A(N, MAX_ABC), B(N, MAX_ABC), C(N, MAX_ABC);
            gen("21_max_01.in", N, X, Y, Z, A, B, C);
        }
        {
            // max - 1
            int N = MAX_N;
            int X = MAX_XYZ, Y = MAX_XYZ, Z = MAX_XYZ;
            vector<int> A(N, MAX_ABC - 1), B(N, MAX_ABC - 1), C(N, MAX_ABC - 1);
            gen("22_max_minus_1_01.in", N, X, Y, Z, A, B, C);
        }
        {
            for (int i = 0; i < 10; i++) {
                int N = MAX_N;
                int X = MAX_XYZ, Y = MAX_XYZ, Z = MAX_XYZ;
                vector<int> A(N, 1), B(N, 1), C(N, 1);
                while (!check_ans_exists(N, X, Y, Z, A, B, C)) {
                    A[rnd.next(N)]++;
                    B[rnd.next(N)]++;
                    C[rnd.next(N)]++;
                }
                gen(format("30_strong_%02d.in", i + 1), N, X, Y, Z, A, B, C);
            }
        }
    }
    return 0;
}