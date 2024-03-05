#include "testlib.h"
#include <bits/stdc++.h>

const int MIN_N = 2;
const int MAX_N = 700;
const int MIN_M = 1;
const int MAX_M = 1000000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int N = inf.readInt(MIN_N, MAX_N, "N"); inf.readSpace();
    int M = inf.readInt(MIN_M, MAX_M, "M"); inf.readEoln();

    std::string S = inf.readToken(format("[LRUD]{%d,%d}",M,M).c_str(), "S"); inf.readEoln();
    
    std::set<std::string> check({"LR","RL","UD","DU"});
    for(int i = 0; i < S.size()-1; i++){
        ensure(check.count(S.substr(i,2)) == 0);
    }
    
    inf.readEof();
    return 0;
}
