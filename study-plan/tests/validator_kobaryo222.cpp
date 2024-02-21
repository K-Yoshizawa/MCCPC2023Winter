#include "testlib.h"
#include "bits/stdc++.h"
#include "constraints.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    int N = inf.readInt(MIN_N, MAX_N, "N");
    inf.readEoln();
    int X = inf.readInt(MIN_XYZ, MAX_XYZ, "X");
    inf.readSpace();
    int Y = inf.readInt(MIN_XYZ, MAX_XYZ, "Y");
    inf.readSpace();
    int Z = inf.readInt(MIN_XYZ, MAX_XYZ, "Z");
    inf.readEoln();
    for (int i = 0; i < N; i++) {
        if (i)
            inf.readSpace();
        int A_i = inf.readInt(MIN_ABC, MAX_ABC, "A_i");
    }
    inf.readEoln();
    for (int i = 0; i < N; i++) {
        if (i)
            inf.readSpace();
        int B_i = inf.readInt(MIN_ABC, MAX_ABC, "B_i");
    }
    inf.readEoln();
    for (int i = 0; i < N; i++) {
        if (i)
            inf.readSpace();
        int C_i = inf.readInt(MIN_ABC, MAX_ABC, "C_i");
    }
    inf.readEoln();
    inf.readEof();
    return 0;
}