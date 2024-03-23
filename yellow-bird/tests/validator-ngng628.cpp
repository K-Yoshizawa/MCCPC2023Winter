# include "testlib.h"
# include <bits/stdc++.h>

constexpr int N_MIN = 1;
constexpr int N_MAX = 1 * int(1e9);
constexpr int M_MIN = 1;
constexpr int M_MAX = 3 * int(1e5);
constexpr int T_MIN = 1;
constexpr int T_MAX = 3;
constexpr int X_MIN = 0;
constexpr int X_MAX = N_MAX;

int main(int argc, char* argv[]){
   registerValidation(argc, argv);
   int n = inf.readInt(N_MIN, N_MAX, "N");
   inf.readSpace();
   int m = inf.readInt(M_MIN, M_MAX, "M");
   inf.readEoln();
   std::multiset<int> st;
   for (int i{}; i < m; i++) {
      int t = inf.readInt(T_MIN, T_MAX, "T");
      inf.readSpace();
      int x = inf.readInt(X_MIN, X_MAX, "X");
      inf.readEoln();
      if (t == 1) {
         inf.ensuref(1 <= x && x <= n, "x range");
         inf.ensuref(st.count(x) == 0, "t == 1");
         st.insert(x);
      }
      if (t == 2) {
         inf.ensuref(1 <= x && x <= n, "x range");
         inf.ensuref(st.count(x) == 1, "t == 2");
         st.erase(st.find(x));
      }
      if (t == 3) {
         inf.ensuref(x == 0, "t == 3");
      }
   }
   inf.readEof();
}
