# include <bits/stdc++.h>

int main() {
   int n, m;
   std::cin >> n >> m;
   std::string s;
   std::cin >> s;

   std::vector<std::string> ans(2*n + 2, std::string(2*n + 2, '#'));
   int y = 2, x = 2;
   for (char c : s) {
      if (c == 'R') x += 1;
      if (c == 'L') x -= 1;
      if (c == 'U') y -= 1;
      if (c == 'D') y += 1;
      if (y < 1 || y > 2*n + 1 || x < 1 || x > 2*n + 1) {
         std::cout << "No\n";
         return 0;
      }
      ans[y][x] = '.';
   }
   if (y != 2*n || x != 2*n) {
      std::cout << "No\n";
      return 0;
   }

   std::cout << "Yes\n";
   for (int i = 1; i <= 2*n + 1; ++i) {
      for (int j = 1; j <= 2*n + 1; ++j) {
         std::cout << ans[i][j];
      }
      std::cout << '\n';
   }
}