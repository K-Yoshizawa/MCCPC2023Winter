# include <bits/stdc++.h>

int main() {
   int t;
   std::cin >> t;
   while (t--) {
      long N, M;
      std::cin >> N >> M;
      long a = (N + M - 1) / M;
      long b = N;
      long g = std::gcd(a, b);
      std::cout << a / g << ' ' << b / g << '\n';
   }
}
