#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MIN_NS = 1;
const int MAX_NS = 1000000000;
const int MIN_M = 1;
const int MAX_M = 100000;

int main(int argc, char *argv[]){
    registerValidation(argc, argv);
    int N = inf.readInt(MIN_NS, MAX_NS, "N"); inf.readSpace();
    inf.readInt(MIN_M, min(N, MAX_M), "M"); inf.readSpace();
    inf.readInt(MIN_NS, MAX_NS, "S");
    inf.readEoln();
    inf.readEof();
}