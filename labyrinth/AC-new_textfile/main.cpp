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
    
    //条件から壁マスであることが決まっている場所を '#' にする
    rep(i,0,n){
        rep(j,0,n){
            if(min({i,j,n-1-i,n-1-j}) == 0) ans[i][j] = '#';
            if((i+1)*(j+1) % 2 == 1) ans[i][j] = '#';
        }
    }
    
    //移動経路上のマスを '@' にする + 移動経路のチェック
    ll x = 1, y = 1;
    ans[x][y] = '@';
    for(auto c : s){
        x += dx[dir[c]], y += dy[dir[c]];

        if(!isinside(x, n) || !isinside(y, n) || ans[x][y] != '.'){
            cout << "No" << endl;
            return 0;
        }

        ans[x][y] = '@';
    }
    if(x != n-2 || y != n-2){
        cout << "No" << endl;
        return 0;
    }
    
    // x mod 2 == 1 (1-indexed) を満たす行については、移動経路上('@')でないマスをすべて壁マスにする
    // x mod 2 == 0 (1-indexed) を満たす行については、"#..@..@....@..#" を "#..@.#@...#@..#" のように壁マスで区切る形にする
    rep(i,0,n){
        bool appeared = false;
        rep(j,0,n){
            appeared |= (ans[i][j] == '@');

            if(i % 2 == 0) ans[i][j] = (ans[i][j] == '@' ? '@' : '#');
            else if(ans[i].substr(j,2) == ".@" && appeared) ans[i][j] = '#';
        }
    }
    
    // '@' を '.' に置き換える
    rep(i,0,n) rep(j,0,n) ans[i][j] = (ans[i][j] == '#' ? '#' : '.');

    cout << "Yes" << endl;
    rep(i,0,n) cout << ans[i] << endl;
}
