#include "testlib.h"
#include <bits/stdc++.h>
//using namespace std;

constexpr int N_MAX = 200000;
constexpr int N_MIN = 1;
constexpr int D_MAX = 200000;
constexpr int D_MIN = 1;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int N = inf.readInt(N_MIN, N_MAX, "N"); inf.readSpace();
    int D = inf.readInt(N, D_MAX, "D"); inf.readEoln();
    
    std::string S = inf.readToken(format("[0-9]{%d}",N));
    
    // N == D の場合は1文字も追加しないので、0が先頭に来てはいけない
    if(N == D) ensure(S.front() != '0');

	inf.readEoln();
	inf.readEof();
	return 0;
}

