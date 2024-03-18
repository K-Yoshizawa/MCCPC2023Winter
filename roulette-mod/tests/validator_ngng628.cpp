# include "testlib.h"
# include <bits/stdc++.h>

const int T_MIN = 1;
const int T_MAX = 1e5;
const int N_MIN = 1;
const int N_MAX = 1e9;
const int M_MIN = 1;
const int M_MAX = 1e9;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int T = inf.readInt(T_MIN, T_MAX, "T");
    inf.readEoln();
    for (int i = 0; i < T; i++) {
        int N = inf.readInt(N_MIN, N_MAX, "N");
        inf.readSpace();
        int M = inf.readInt(M_MIN, M_MAX, "M");
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}