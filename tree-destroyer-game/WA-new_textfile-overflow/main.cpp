#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vint;
typedef vector<vint> vvint;

#define rep(i,a,n) for(int i = a; i < n; i++)

int main(){
    int n;
    cin >> n;

    vvint G_undirected(n);
    rep(i,0,n-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G_undirected[a].emplace_back(b);
        G_undirected[b].emplace_back(a);
    }

    vint dist(n, 1 << 30);
    dist[0] = 0;
    queue<int> que;
    que.emplace(0);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        
        for(auto nv : G_undirected[v]){
            if(dist[nv] > dist[v] + 1){
                dist[nv] = dist[v] + 1;
                que.emplace(nv);
            }
        }
    }
    
    vvint G(n);
    rep(v,0,n) for(auto nv : G_undirected[v]) if(dist[nv] > dist[v]) G[v].emplace_back(nv);

    vector<bool> visited(n);
    long long int ans = 0;
    rep(i,0,n-1){
        int x; cin >> x;
        x--;
        if(!visited[x]){
            visited[x] = true;
            
            int erasedcnt = 1;
            que.emplace(x);
            while(!que.empty()){
                int v = que.front();
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

