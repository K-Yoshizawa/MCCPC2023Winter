#include "testlib.h"
#include "bits/stdc++.h"
#include "constraints.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
    int N = inf.readInt(MIN_N, MAX_N, "N");
    inf.readSpace();
    int M = inf.readInt(MIN_M, MAX_M, "M");
    inf.readSpace();
    int S = inf.readInt(MIN_S, MAX_S, "S");
    inf.readEoln();
    inf.readEof();
    assert(M <= N);
    return 0;
}