# include <stdio.h>
# define MOD (998244353)

int powmod(int a, int b, int mod) {
   if (b == 0) {
      return 1 % mod;
   }
   int ans = (long long)powmod(a, b / 2, mod);
   ans = (long long)ans * ans % mod;
   if (b % 2 == 1) {
      ans = (long long)ans * a % mod;
   }
   return ans;
}

int main(void) {
   int N, M, S;
   scanf("%d%d%d", &N, &M, &S);

   int ans = 1 % MOD;
   for (int i = 1; i < M; i++) {
      ans = ((long long)ans * (S - i) % MOD) * powmod(i, MOD - 2, MOD) % MOD;
   }

   printf("%d\n", ans);
}