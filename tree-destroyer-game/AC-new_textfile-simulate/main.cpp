#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pll;
#define rep(i,a,n) for(ll i = a; i < n; i++)

int main(){
    ll n;
    cin >> n;

    //vector<set<ll>> で隣接リストを作る
    vector<set<ll>> G(n);
    rep(i,0,n-1){
        ll a,b; 
        cin >> a >> b;
        a--; b--;

        G[a].insert(b);
        G[b].insert(a);
    }
    
    //各頂点の親を記録 + 親方向への辺をGから削除
    vector<ll> parent(n);
    queue<pll> que;
    que.emplace(0,-1);
    while(!que.empty()){
        auto [v, p] = que.front();
        que.pop();
        
        parent[v] = p;
        G[v].erase(p);
        for(auto nv : G[v]){
            que.emplace(nv, v);
        }
    }
    
    ll ans = 0;
    rep(i,0,n-1){
        ll x;
        cin >> x;
        x--;
        
        //xの親からたどり着ける頂点を削除する(xの親自身は削除しない)
        if(G[parent[x]].count(x) > 0){
            G[parent[x]].erase(x);

            ll count = 0;
            queue<ll> que;
            que.emplace(x);
            
            while(!que.empty()){
                ll v = que.front();
                que.pop();
                count++;

                for(auto nv : G[v]) que.emplace(nv);
                G[v].clear();
            }
            
            ans += count*count;
        }
    }
    
    cout << ans << endl;
}
