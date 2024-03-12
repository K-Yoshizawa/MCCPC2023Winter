# include <stdio.h>
# define N_MAX (1500)
# define M_MAX (2 * N_MAX * N_MAX)
void swap(int *a, int *b) { int tmp = *a; *a = *b; *b = tmp; }

# pragma region UnionFind
int par[(2*N_MAX + 1) * (2*N_MAX + 1) + 2*(2*N_MAX + 1) + 3];
int rank[(2*N_MAX + 1) * (2*N_MAX + 1) + 2*(2*N_MAX + 1) + 3];

void init(int n) {
   for (int i = 1; i <= n; i++) {
      par[i] = i;
      rank[i] = 0;
   }
}

int find(int x) {
   if (par[x] == x) {
      return x;
   }
   else {
      return par[x] = find(par[x]);
   }
}

void unite(int x, int y) {
   x = find(x);
   y = find(y);
   if (x == y) return;

   if (rank[x] < rank[y]) {
      par[x] = y;
   }
   else {
      par[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
   }
}

int same(int x, int y) {
   return find(x) == find(y);
}
# pragma endregion UnionFind


char ans[2*N_MAX + 2][2*N_MAX + 3];  // メモリ使用量が大きいのでグローバル変数にする
int main(void) {
   //────────────────────────────────────────────────────────────────────
   // 1. 入力
   //────────────────────────────────────────────────────────────────────
   int n, m;
   scanf("%d%d", &n, &m);
   char s[M_MAX + 2];  // 最悪のケースで問題ないようにメモリを広めに確保
   scanf("%s", s + 1);  // 1-indexed にするために s + 1 にしている
   int height = 2*n + 1;
   int width = 2*n + 1;

   //────────────────────────────────────────────────────────────────────
   // 2. 「要件」より s に依存せずに床か壁かが決まる場所を埋める
   //────────────────────────────────────────────────────────────────────
   for (int i = 0; i < 2*N_MAX + 2; i++) {
      for (int j = 0; j < 2*N_MAX + 3; j++) {
         ans[i][j] = '\0';
      }
   }
   for (int i = 1; i <= height; i++) {
      for (int j = 1; j <= width; j++) {
         if (i == 1 || j == 1 || i == height || j == width) {
            ans[i][j] = '#';
         }
         else if (i % 2 == 0 && j % 2 == 0) {
            ans[i][j] = '.';
         }
         else if (i % 2 == 1 && j % 2 == 1) {
            ans[i][j] = '#';
         }
         else {
            ans[i][j] = '?';
         }
      }
   }

   //────────────────────────────────────────────────────────────────────
   // 3. s をシミュレーションして必ず雪ず床にするべき場所を
   //    求めておく。また、(2n + 1) x (2n + 1) に到達するかを判定する。
   //────────────────────────────────────────────────────────────────────
   int y = 2, x = 2;
   for (int i = 1; i <= m; i++) {
      if (s[i] == 'U') y--;
      if (s[i] == 'D') y++;
      if (s[i] == 'L') x--;
      if (s[i] == 'R') x++;
      if (ans[y][x] == '#') {
         printf("No\n");
         return 0;
      }
      ans[y][x] = '.';
   }

   if (y != 2*n || x != 2*n) {
      printf("No\n");
      return 0;
   }

   //────────────────────────────────────────────────────────────────────
   // 4. UnionFind で通行可能な床をグループ化する
   //    マス (i, j) を頂点 i*width + j と割り振る。
   //────────────────────────────────────────────────────────────────────
   init(height * width + 2*width + 1);

   int di[5] = {0, 0, 1, 0, -1};
   int dj[5] = {0, 1, 0, -1, 0};
   for (int i = 1; i <= height; i++) {
      for (int j = 1; j <= width; j++) {
         if (ans[i][j] != '.') {
            continue;
         }
         for (int k = 1; k <= 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni < 1 || ni > height || nj < 1 || nj > width) {
               continue;
            }
            if (ans[ni][nj] == '.') {
               int u = i * width + j;
               int v = ni * width + nj;
               unite(u, v);
            }
         }
      }
   }

   //────────────────────────────────────────────────────────────────────
   // 5. 床と壁を適当に確定させる
   //    `?` であるようなマスのうち、そこを床にしてもよいかを判定する感じ
   //────────────────────────────────────────────────────────────────────
   for (int i = 1; i <= height; i++) {
      for (int j = 1; j <= width; j++) {
         if (ans[i][j] != '?') {
            continue;
         }
         for (int k1 = 1; k1 <= 4; k1++) {
            for (int k2 = 1; k2 <= 4; k2++) {
               if (k1 == k2) continue;
               int ni1 = i + di[k1], nj1 = j + dj[k1];
               int ni2 = i + di[k2], nj2 = j + dj[k2];
               if (ni1 < 1 || ni1 > height || nj1 < 1 || nj1 > width) continue;
               if (ni2 < 1 || ni2 > height || nj2 < 1 || nj2 > width) continue;
               if (ans[ni1][nj1] == '.' && ans[ni2][nj2] == '.') {
                  int v1 = ni1 * width + nj1;
                  int v2 = ni2 * width + nj2;
                  if (same(v1, v2)) {
                     ans[i][j] = '#';
                  }
               }
            }
         }
         if (ans[i][j] == '?') {
            ans[i][j] = '.';
            for (int k1 = 1; k1 <= 4; k1++) {
               int ni = i + di[k1], nj = j + dj[k1];
               if (ni < 1 || ni > height || nj < 1 || nj > width || ans[ni][nj] != '.') {
                  continue;
               }
               unite(i * width + j, ni * width + nj);
            }
         }
      }
   }

   //────────────────────────────────────────────────────────────────────
   // 6. 本当に要件を満たしているかを判定する
   //────────────────────────────────────────────────────────────────────
   // int leader = find(2*width + 2);
   // for (int i = 1; i <= height; i++) {
   //    for (int j = 1; j <= width; j++) {
   //       if (ans[i][j] == '.') {
   //          if (leader != find(i * width + j)) {
   //             printf("No\n");
   //             return 0;
   //          }
   //       }
   //    }
   // }

   //────────────────────────────────────────────────────────────────────
   // 7. 出力
   //────────────────────────────────────────────────────────────────────
   printf("Yes\n");
   for (int i = 1; i <= height; i++) {
      printf("%s\n", ans[i] + 1);
   }
}