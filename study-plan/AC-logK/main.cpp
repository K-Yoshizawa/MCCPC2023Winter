#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, X, Y, Z; cin >> N >> X >> Y >> Z;
    vector<int> A(N), B(N), C(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < N; ++i) cin >> B[i];
    for(int i = 0; i < N; ++i) cin >> C[i];

    vector pre(N + 1, vector(310, vector(310, -1)));
    vector ofs(N + 1, vector(310, vector(310, 0)));
    vector dp(N + 1, vector(310, vector(310, -1)));
    dp[0][0][0] = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j <= 300; ++j){
            for(int k = 0; k <= 300; ++k){
                if(dp[i][j][k] == -1) continue;
                int nj = min(300, j + A[i]), nk = min(300, k + B[i]);
                if(dp[i + 1][nj][k] < dp[i][j][k]){
                    dp[i + 1][nj][k] = dp[i][j][k];
                    pre[i + 1][nj][k] = 0;
                    ofs[i + 1][nj][k] = max(0, j + A[i] - 300);
                }
                if(dp[i + 1][j][nk] < dp[i][j][k]){
                    dp[i + 1][j][nk] = dp[i][j][k];
                    pre[i + 1][j][nk] = 1;
                    ofs[i + 1][j][nk] = max(0, k + B[i] - 300);
                }
                if(dp[i + 1][j][k] < dp[i][j][k] + C[i]){
                    dp[i + 1][j][k] = dp[i][j][k] + C[i];
                    pre[i + 1][j][k] = 2;
                }
            }
        }
    }
    
    int a = -1, b = -1;
    for(int j = X; j <= 300; ++j){
        for(int k = Y; k <= 300; ++k){
            if(dp[N][j][k] >= Z){
                a = j, b = k;
            }
        }
    }
    if(a == -1 and b == -1){
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    for(int i = N; i > 0; --i){
        int p = pre[i][a][b];
        ans.push_back(p);
        switch(p){
            case 0 :
                a -= A[i - 1] - ofs[i][a][b];
                break;
            case 1 :
                b -= B[i - 1] - ofs[i][a][b];
                break;
            case 2 :
                break;
        }
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < N; ++i){
        cout << ans[i] << (i + 1 == N ? "\n" : " ");
    }
}