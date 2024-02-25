#include "testlib.h"
#include "constraints.hpp"
#include <bits/stdc++.h>

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int T = inf.readInt(MIN_T, MAX_T, "T"); inf.readEoln();

    for(int i = 0; i < T; i++){
        int N = inf.readInt(MIN_N, MAX_N, "N"); inf.readSpace();
        int M = inf.readInt(MIN_M, MAX_M, "M"); 
        
        if(i < T-1) inf.readEoln();
    }
    inf.readEof();
    return 0;
}
