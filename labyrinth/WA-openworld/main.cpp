# include <bits/stdc++.h>

int main() {
   int n, m;
   std::cin >> n >> m;
   std::string s;
   std::cin >> s;

   std::cout << "Yes\n";
   for (int i = 1; i <= 2*n + 1; i++) {
      for (int j = 1; j <= 2*n + 1; j++) {
         if (i == 1 || j == 1 || i == 2*n + 1 || j == 2*n + 1) {
            std::cout << '#';
         }
         else {
            std::cout << '.';
         }
      }
      std::cout << "\n";
   }
}