#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = 0; i < N; ++i)
        cin >> B[i];
    for (int i = 0; i < N; ++i)
        cin >> C[i];

    using tp = tuple<int, int, int, int>;

    vector dp(N + 1, vector(X + 1, vector(Y + 1, vector(Z + 1, tp(-1, -1, -1, -1)))));
    dp[0][0][0][0] = tp(0, 0, 0, 0);
    for (int i = 0; i < N; ++i) {
        for (int x = 0; x <= X; ++x) {
            for (int y = 0; y <= Y; ++y) {
                for (int z = 0; z <= Z; z++) {
                    if (dp[i][x][y][z] == tp(-1, -1, -1, -1))
                        continue;
                    dp[i + 1][min(x + A[i], X)][y][z] = tp(0, x, y, z);
                    dp[i + 1][x][min(y + B[i], Y)][z] = tp(1, x, y, z);
                    dp[i + 1][x][y][min(z + C[i], Z)] = tp(2, x, y, z);
                }
            }
        }
    }

    if (dp[N][X][Y][Z] == tp(-1, -1, -1, -1)) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    int x = X, y = Y, z = Z;
    for (int i = N; i > 0; --i) {
        auto [t, nx, ny, nz] = dp[i][x][y][z];
        ans.push_back(t);
        x = nx;
        y = ny;
        z = nz;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << (i + 1 == N ? "\n" : " ");
    }
}