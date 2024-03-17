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
    
    //S は 1 以外の数字からなる文字列
    std::string S = inf.readToken(format("[02-9]{%d}",N));
    
    // N == D の場合は1文字も追加しないので、0が先頭に来てはいけない(ただし、S = "0" は例外)
    if(N == D && N > 1) ensure(S.front() != '0');

	inf.readEoln();
	inf.readEof();
	return 0;
}

