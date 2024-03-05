#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int MIN_N = 1;
const int MIN_M = 1;
const int MIN_S = 1;

const int MAX_N = 1000000000;
const int MAX_M = 100000;
const int MAX_S = 1000000000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int N = inf.readInt(MIN_N, MAX_N, "N"); inf.readSpace();
    int M = inf.readInt(MIN_M, min(N, MAX_M), "M"); inf.readSpace();
    int S = inf.readInt(MIN_S, MAX_S, "S");
    inf.readEoln();
    inf.readEof();
    return 0;
}
