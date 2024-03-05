#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pll;

#define rep(i,a,n) for(ll i = a; i < n; i++)

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

bool isinside(ll i, ll n){return 0 <= i && i < n; }

int main(){
    ll n,m;
    cin >> n >> m;
    n = 2*n + 1;

    string s;
    cin >> s;

    map<char,ll> dir;
    rep(i,0,4) dir["LURD"[i]] = i;

    vector<string> ans(n, string(n, '.'));
    vector used(n, vector<bool>(n));
    
    //条件から壁マスであることが決まっている場所を '#' にする
    rep(i,0,n){
        rep(j,0,n){
            if(min({i,j,n-1-i,n-1-j}) == 0) ans[i][j] = '#';
            if(i % 2 == 0 && j % 2 == 0) ans[i][j] = '#';
            
            used[i][j] = (ans[i][j] == '#');
        }
    }
    
    //移動経路のチェック
    ll x = 1, y = 1;
    used[x][y] = true;
    for(auto c : s){
        x += dx[dir[c]], y += dy[dir[c]];

        if( !isinside(x, n) || !isinside(y, n) || used[x][y]){
            cout << "No" << endl;
            return 0;
        }
        used[x][y] = true;
    }
    if(x != n-2 || y != n-2){
        cout << "No" << endl;
        return 0;
    }

    //移動経路上のマスからBFSをし、四近傍がすでに訪問済み or 移動できないなら '#' とする
    //ここ、正当性を示せていません(変な探索のしかたをするとWAになります)
    x = 1, y = 1;
    for(auto c : s){
        rep(i,0,4){
            ll sx = x + dx[i], sy = y + dy[i];
            
            if(!used[sx][sy]){
                used[sx][sy] = true;
                queue<pll> que;
                que.emplace(sx,sy);
                
                while(!que.empty()){
                    auto [currx, curry] = que.front();
                    que.pop();
                    
                    bool isleaf = true;
                    rep(k,0,4){
                        ll nextx = currx + dx[k], nexty = curry + dy[k];
                        
                        if(used[nextx][nexty]) continue;
                        used[nextx][nexty] = true;
                        que.emplace(nextx,nexty);
                        isleaf = false;
                    }

                    if(isleaf && (currx+curry) % 2 == 1){
                        used[currx][curry] = true;
                        ans[currx][curry] = '#';
                    }
                }
            }
        } 
        x += dx[dir[c]], y += dy[dir[c]];
    }
    
    cout << "Yes" << endl;
    rep(i,0,n) cout << ans[i] << endl;
}
