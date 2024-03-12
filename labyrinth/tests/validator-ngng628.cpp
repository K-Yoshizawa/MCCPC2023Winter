# include <bits/stdc++.h>
# include "testlib.h"

const int N_MIN = 1;
const int N_MAX = 700;
const int M_MIN = 1;
const int M_MAX = 1e6;

int main(int argc, char* argv[]) {
   registerValidation(argc, argv);
   int N = inf.readInt(N_MIN, N_MAX, "N");
   inf.readSpace();
   int M = inf.readInt(M_MIN, M_MAX, "M");
   inf.readEoln();
   std::string S = inf.readToken(format("[LRUD]{%d}", M).c_str(), "S");
   for (int i = 0; i < M - 1; i++) {
      if (S[i] == 'L') inf.ensuref(S[i + 1] != 'R', "LR, UD は隣接しない");
      if (S[i] == 'R') inf.ensuref(S[i + 1] != 'L', "LR, UD は隣接しない");
      if (S[i] == 'U') inf.ensuref(S[i + 1] != 'D', "LR, UD は隣接しない");
      if (S[i] == 'D') inf.ensuref(S[i + 1] != 'U', "LR, UD は隣接しない");
   }
   inf.readEoln();
   inf.readEof();
   return 0;
}
