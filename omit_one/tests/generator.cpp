# include "testlib.h"
# include <bits/stdc++.h>

constexpr int N_MAX = 2 * int(1e5);
constexpr int N_MIN = 1;
constexpr int D_MAX = 2 * int(1e5);
constexpr int D_MIN = 1;

int main(int argc, char* argv[]) {
   registerGen(argc, argv, 1);

   // サンプル
   {
      std::ofstream of("00_sample_01.in");
      of << "3 4" << std::endl;
      of << "314" << std::endl;
      of.close();
   }
   {
      std::ofstream of("00_sample_02.in");
      of << "2 3" << std::endl;
      of << "00" << std::endl;
      of.close();
   }

   // 完全ランダム
   for (int ts{1}; ts <= 10; ts++) {
      std::ofstream of(format("01_random_%2d.in", ts).c_str());
      int n{1}, d{};
      while (n > d) {
         n = rnd.next(N_MIN, N_MAX);
         d = rnd.next(D_MIN, D_MAX);
      }
      of << n << ' ' << d << std::endl;
      of << rnd.next(format("[0-9]{%d}", n)) << std::endl;
      of.close();
   }

   // 0 と 1 のみ
   for (int ts{1}; ts <= 3; ts++) {
      std::ofstream of(format("02_only01_%2d.in", ts).c_str());
      int n{1}, d{};
      while (n > d) {
         n = rnd.next(N_MIN, N_MAX);
         d = rnd.next(D_MIN, D_MAX);
      }
      of << n << ' ' << d << std::endl;
      of << rnd.next(format("[0-1]{%d}", n)) << std::endl;
      of.close();
   }

   // かならず 0 が 1 つ以上
   for (int ts{1}; ts <= 5; ts++) {
      std::ofstream of(format("03_s0s_%2d.in", ts).c_str());
      int n{1}, d{};
      while (n > d) {
         n = rnd.next(4, N_MAX);
         d = rnd.next(D_MIN, D_MAX);
      }

      int t = rnd.next(1, n - 1);
      int m1 = t;
      int m2 = n - t - 1;

      of << n << ' ' << d << std::endl;
      of << rnd.next(format("[0-9]{%d}0[0-9]{%d}", m1, m2)) << std::endl;
      of.close();
   }
}
