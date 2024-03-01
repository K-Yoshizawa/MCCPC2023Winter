#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define rep(i,a,n) for(ll i = a; i < n; i++)

int main(){
    ll n;
    cin >> n;

    vvll G_undirected(n);
    rep(i,0,n-1){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G_undirected[a].emplace_back(b);
        G_undirected[b].emplace_back(a);
    }

    vll dist(n, 1ll << 60);
    dist[0] = 0;
    queue<ll> que;
    que.emplace(0);
    while(!que.empty()){
        ll v = que.front();
        que.pop();
        
        for(auto nv : G_undirected[v]){
            if(dist[nv] > dist[v] + 1){
                dist[nv] = dist[v] + 1;
                que.emplace(nv);
            }
        }
    }
    
    vvll G(n);
    rep(v,0,n) for(auto nv : G_undirected[v]) if(dist[nv] > dist[v]) G[v].emplace_back(nv);

    vector<bool> visited(n);
    ll ans = 0;
    rep(i,0,n-1){
        ll x; cin >> x;
        x--;
        if(!visited[x]){
            visited[x] = true;
            
            ll erasedcnt = 1;
            que.emplace(x);
            while(!que.empty()){
                ll v = que.front();
                que.pop();

                for(auto nv : G[v]){
                    if(!visited[nv]){
                        visited[nv] = true;
                        erasedcnt++;
                        que.emplace(nv);
                    }
                }
            }

            ans += erasedcnt*erasedcnt;
        }
    }

    cout << ans << endl;

}

