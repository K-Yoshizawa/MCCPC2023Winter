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
   std::string s = inf.readWord(format("[023456789]{%d}", n));
   inf.readEoln();
   inf.readEof();

   // 念の為チェック
   for (char c : s) {
      inf.ensuref(c != '1', "bat 1");
   }

   if (n == d) {
      bool all0 = true;
      for (char c : s) {
         all0 &= c == '0';
      }
      inf.ensuref(!all0, "all 0 && n == d");
   }

   return 0;
}
