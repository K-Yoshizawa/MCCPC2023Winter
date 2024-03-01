# include <stdio.h>
# include <stdbool.h>

int main(void) {
   int n, d;
   scanf("%d%d", &n, &d);
   char s[2 * 100000 + 2];
   scanf("%s", s);

   bool inserted = false;
   for (int i = 0; i <= n; i++) {
      if (!inserted && (i == n || s[i] == '0')) {
         for (int j = 0; j < d - n; j++) {
            printf("1");
         }
         inserted = true;
      }
      printf("%c", s[i]);
   }
   printf("\n");

   return 0;
}
