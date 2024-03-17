#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, X, Y, Z; cin >> N >> X >> Y >> Z;
    vector<int> A(N), B(N), C(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < N; ++i) cin >> B[i];
    for(int i = 0; i < N; ++i) cin >> C[i];

    vector dp(N + 1, vector(310, vector(310, -1)));
    dp[0][0][0] = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j <= 300; ++j){
            for(int k = 0; k <= 300; ++k){
                if(dp[i][j][k] == -1) continue;
                if(j + A[i] <= 300) dp[i + 1][j + A[i]][k] = max(dp[i + 1][j + A[i]][k], dp[i][j][k]);
                if(k + B[i] <= 300) dp[i + 1][j][k + B[i]] = max(dp[i + 1][j][k + B[i]], dp[i][j][k]);
                dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + C[i]);
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
        if(a - A[i - 1] >= 0 and dp[i - 1][a - A[i - 1]][b] == dp[i][a][b]){
            ans.push_back(0);
            a -= A[i - 1];
        }
        else if(b - B[i - 1] >= 0 and dp[i - 1][a][b - B[i - 1]] == dp[i][a][b]){
            ans.push_back(1);
            b -= B[i - 1];
        }
        else{
            ans.push_back(2);
        }
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < N; ++i){
        cout << ans[i] << (i + 1 == N ? "\n" : " ");
    }
}