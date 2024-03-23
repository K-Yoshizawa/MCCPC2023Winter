#include "testlib.h"
#include "bits/stdc++.h"

using namespace std;

const int MIN_N = 1;
const int MAX_N = 300'000;
const int MIN_M = 1;
const int MAX_M = 300'000;
const int MIN_x = 0;
int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
    int N = inf.readInt(MIN_N, MAX_N, "N");
    inf.readSpace();
    int M = inf.readInt(MIN_M, MAX_M, "M");
    inf.readEoln();
    vector<bool> vis(N + 1);
    for (int i = 0; i < M; i++) {
        int t = stoi(inf.readToken(pattern("[1-3]"), "t_i"));
        inf.readSpace();
        int x = inf.readInt(MIN_x, N, "x_i");
        inf.readEoln();
        if (t == 1) {
            assert(!vis[x]);
            vis[x] = true;
            assert(x >= 1);
        } else if (t == 2) {
            assert(vis[x]);
            vis[x] = false;
            assert(x >= 1);
        } else {
            assert(x == 0);
        }
    }
    inf.readEof();
    return 0;
}