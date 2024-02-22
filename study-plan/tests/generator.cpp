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
    }
    return 0;
}