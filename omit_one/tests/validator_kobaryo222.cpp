#include "testlib.h"
#include "bits/stdc++.h"

using namespace std;

const int MIN_N = 1;
const int MAX_N = 200'000;
const int MIN_D = 1;
const int MAX_D = 200'000;

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
    int N = inf.readInt(MIN_N, MAX_N, "N");
    inf.readSpace();
    int D = inf.readInt(MIN_D, MAX_D, "D");
    inf.readEoln();
    assert(N <= D);
    string S = inf.readToken(format("[0-9]{%d}", N), "S");
    inf.readEoln();
    inf.readEof();
    return 0;
}