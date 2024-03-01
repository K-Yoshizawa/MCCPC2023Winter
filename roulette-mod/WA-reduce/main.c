# include <stdio.h>

int main(void) {
   int t;
   scanf("%d", &t);
   while (t--) {
      int n, m;
      scanf("%d%d", &n, &m);
      int a = 1 + (n - 1) / m;
      int b = n;
      printf("%d %d\n", a, b);
   }
}
