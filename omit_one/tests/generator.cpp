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
      of << "354" << std::endl;
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
      std::ofstream of(format("01_random_%02d.in", ts).c_str());
      int n{1}, d{};
      while (n > d) {
         n = rnd.next(N_MIN, N_MAX);
         d = rnd.next(D_MIN, D_MAX);
      }
      of << n << ' ' << d << std::endl;
      of << rnd.next(format("[023456789]{%d}", n)) << std::endl;
      of.close();
   }

   // 0 と 9 のみ
   for (int ts{1}; ts <= 3; ts++) {
      std::ofstream of(format("02_only09_%02d.in", ts).c_str());
      int n{1}, d{};
      while (n > d) {
         n = rnd.next(N_MIN, N_MAX);
         d = rnd.next(D_MIN, D_MAX);
      }
      of << n << ' ' << d << std::endl;
      of << rnd.next(format("[09]{%d}", n)) << std::endl;
      of.close();
   }

   // かならず 0 が 1 つのみ
   for (int ts{1}; ts <= 2; ts++) {
      std::ofstream of(format("03_s0s_%02d.in", ts).c_str());
      int n{1}, d{};
      while (n > d) {
         n = rnd.next(4, N_MAX);
         d = rnd.next(D_MIN, D_MAX);
      }

      int t = rnd.next(1, n - 1);
      int m1 = t;
      int m2 = n - t - 1;

      of << n << ' ' << d << std::endl;
      of << rnd.next(format("[23456789]{%d}0[23456789]{%d}", m1, m2)) << std::endl;
      of.close();
   }

   // N のでかつよケース
   for (int ts{1}; ts <= 3; ts++) {
      std::ofstream of(format("04_max_n_%02d.in", ts).c_str());
      int n{N_MAX - (ts - 1)};
      int d{rnd.next(n, D_MAX)};
      of << n << ' ' << d << std::endl;
      of << rnd.next(format("[09]{%d}", n)) << std::endl;
   }

   // N = 1, ..., 3 && d = D_MAX - eps のケース
   for (int ts{1}; ts <= 10; ts++) {
      std::ofstream of(format("05_max_d_%02d.in", ts).c_str());
      int n{rnd.next(1, 3)};
      int d{rnd.next(D_MAX - 3, D_MAX)};
      of << n << ' ' << d << std::endl;
      of << rnd.next(format("[09]{%d}", n)) << std::endl;
   }

   // 0 のみ
   for (int ts{1}; ts <= 5; ts++) {
      std::ofstream of(format("06_all_0_%02d.in", ts).c_str());
      int n{rnd.next(N_MIN, N_MAX)};
      if (ts == 1) {
         n = 1;
      }
      else if (ts == 5) {
         n = N_MAX - 1;
      }
      int d{rnd.next(D_MAX - 3, D_MAX)};
      if (ts == 5) 
         d = D_MAX;
      of << n << ' ' << d << std::endl;
      of << rnd.next(format("[0]{%d}", n)) << std::endl;
   }
   
   // 9 のみ
   for (int ts{1}; ts <= 2; ts++) {
      std::ofstream of(format("07_all_9_%02d.in", ts).c_str());
      int n{rnd.next(N_MIN, N_MAX)};
      if (ts == 1) {
         n = 1;
      }
      int d{rnd.next(D_MAX - 3, D_MAX)};
      of << n << ' ' << d << std::endl;
      of << rnd.next(format("[9]{%d}", n)) << std::endl;
   }
}
