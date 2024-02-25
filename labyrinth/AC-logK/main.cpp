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

    vector<vector<int>> vis(n, vector<int>(n, 0));
    vis[1][1] = 1;
    auto checker = [&](int y, int x){
        if(y == 0 or x == 0 or y == n - 1 or x == n - 1){
            return false;
        }
        if(y % 2 == 0 and x % 2 == 0) return false;
        return true;
    };
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
        if(checker(ny, nx) and !vis[ny][nx]){
            vis[ny][nx] = 1;
            ans[ny][nx] = '.';
            y = ny, x = nx;
        }
        else{
            cout << "No" << endl;
            return 0;
        }
    }
    if(!(y == n - 2 and x == n - 2)){
        cout << "No" << endl;
        return 0;
    }

    for(int y = 1; y < n; y += 2){
        for(int x = 1; x < n; x += 2){
            if(vis[y][x]) continue;
            vis[y][x] = 1;
            for(auto c : "LRUD"){
                auto [dy, dx] = movedict[c];
                int my = y + dy, mx = x + dx;
                int ny = y + dy * 2, nx = x + dx * 2;
                if(checker(ny, nx) and vis[ny][nx]){
                    ans[my][mx] = '.';
                    break;
                }
            }
        }
    }

    cout << "Yes" << endl;
    for(auto v : ans){
        cout << v << endl;
    }
}