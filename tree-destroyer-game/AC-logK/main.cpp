#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<vector<int>> G(N + 1);
    for(int i = 0; i < N - 1; ++i){
        int A, B; cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    vector<int> x(N - 1);
    for(auto &xx : x) cin >> xx;

    vector<int> parent(N + 1, 0);
    auto dfs1 = [&](auto self, int v, int p) -> void {
        parent[v] = p;
        for(auto u : G[v]){
            if(u == p) continue;
            self(self, u, v);
        }
    };
    dfs1(dfs1, 1, 0);

    vector<int> used(N + 1, 0);
    auto dfs2 = [&](auto self, int v) -> long long {
        if(used[v]) return 0;
        used[v] = 1;
        long long ret = 1;
        for(auto u : G[v]){
            if(u == parent[v]) continue;
            if(used[u]) continue;
            ret += self(self, u);
        }
        return ret;
    };

    long long ans = 0;
    for(auto v : x){
        long long s = dfs2(dfs2, v);
        ans += s * s;
    }
    cout << ans << endl;
}

