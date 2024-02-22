# include "testlib.h"
# include <bits/stdc++.h>

constexpr int N_MAX = 2 * int(1e5);
constexpr int N_MIN = 1;
constexpr int D_MAX = 2 * int(1e5);
constexpr int D_MIN = 1;

int main(int argc, char* argv[]) {
   registerValidation(argc, argv);
   
   int n = inf.readInt(N_MIN, N_MAX, "A");
   inf.readSpace();
   int d = inf.readInt(D_MIN, D_MAX, "B");
   inf.ensuref(n <= d, "LEQ");
   inf.readEoln();
   inf.readWord(format("[0-9]{%d}", n));
   inf.readEoln();
   inf.readEof();
   
   return 0;
}
