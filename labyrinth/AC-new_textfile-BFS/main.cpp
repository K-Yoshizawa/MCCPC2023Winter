#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pll;

#define rep(i,a,n) for(ll i = a; i < n; i++)

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

int main(){
    ll n,m;
    cin >> n >> m;
    n = 2*n + 1;

    string s;
    cin >> s;

    vector<string> ans(n, string(n, '.'));
    vector used(n, vector<bool>(n));
    
    //(奇数, 奇数)のマスを '#' にする
    rep(i,0,n) rep(j,0,n) if(i % 2 == 0 && j % 2 == 0) ans[i][j] = '#', used[i][j] = true;
    
    auto isinside = [&n](ll pos_x, ll pos_y){
        return 0 <= min(pos_x, pos_y) && max(pos_x, pos_y) < n;
    };
    

    //移動経路のチェック
    map<char,ll> idx;
    rep(i,0,4) idx["LURD"[i]] = i;

    ll x_path = 1, y_path = 1;
    used[x_path][y_path] = true;
    for(auto c : s){
        x_path += dx[idx[c]], y_path += dy[idx[c]];

        if(!isinside(x_path, y_path) || used[x_path][y_path]){
            cout << "No" << endl;
            return 0;
        }
        used[x_path][y_path] = true;
    }
    if(x_path != n-2 || y_path != n-2){
        cout << "No" << endl;
        return 0;
    }


    //移動経路上のマスからBFSをし、四近傍すべてが 訪問済み or 壁 or 範囲外 なら '#' とする
    x_path = 1, y_path = 1;
    rep(i,0,m+1){
        char c = s[i];

        rep(dir_path,0,4){
            ll nx_path = x_path + dx[dir_path], ny_path = y_path + dy[dir_path];
            
            if(!used[nx_path][ny_path]){
                used[nx_path][ny_path] = true;
                queue<pll> que;
                que.emplace(nx_path,ny_path);
                
                while(!que.empty()){
                    auto [x, y] = que.front();
                    que.pop();
                    
                    bool isleaf = true;
                    rep(dir,0,4){
                        ll nx = x + dx[dir], ny = y + dy[dir];
                        
                        if(!isinside(nx, ny) || used[nx][ny]) continue;
                        used[nx][ny] = true;
                        que.emplace(nx,ny);
                        isleaf = false;
                    }

                    if(isleaf){
                        used[x][y] = true;
                        ans[x][y] = '#';
                    }
                }
            }
        } 
        
        if(i < m) x_path += dx[idx[c]], y_path += dy[idx[c]];
    }
    
    cout << "Yes" << endl;
    rep(i,0,n) cout << ans[i] << endl;
}
