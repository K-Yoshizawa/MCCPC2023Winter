#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M; cin >> N >> M;
    string S; cin >> S;

    int n = 2 * N + 1;
    vector<string> ans(n, string(n, '.'));
    for(int i = 0; i < n; ++i){
        ans[0][i] = ans[n - 1][i] = ans[i][0] = ans[i][n - 1] = '#';
    }
    for(int i = 2; i < n; i += 2){
        for(int j = 0; j < n; ++j){
            ans[i][j] = ans[j][i] = '#';
        }
    }

    int y = 1, x = 1;
    using p = pair<int, int>;
    map<char, p> movedict;
    movedict['L'] = p(0, -1);
    movedict['R'] = p(0, 1);
    movedict['U'] = p(-1, 0);
    movedict['D'] = p(1, 0);
    for(int m = 0; m < M; ++m){
        auto [dy, dx] = movedict[S[m]];
        int ny = y + dy, nx = x + dx;
        ans[ny][nx] = '.';
        y = ny, x = nx;
    }

    cout << "Yes" << endl;
    for(auto v : ans){
        cout << v << endl;
    }
}