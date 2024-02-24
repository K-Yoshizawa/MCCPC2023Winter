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
    vector<long long> subtree(N + 1, 0);
    auto dfs1 = [&](auto self, int v, int p) -> long long {
        parent[v] = p;
        long long s = 1;
        for(auto u : G[v]){
            if(u == p) continue;
            s += self(self, u, v);
        }
        return subtree[v] = s;
    };
    dfs1(dfs1, 1, 0);

    vector<int> used(N + 1, 0);

    long long ans = 0;
    for(auto v : x){
        used[v] = 1;
        int u = parent[v];
        bool exist = true;
        while(u != 0){
            exist &= (!used[u]);
            u = parent[u];
        }
        if(!exist) continue;
        ans += subtree[v] * subtree[v];
        u = parent[v];
        while(u != 0){
            subtree[u] -= subtree[v];
            u = parent[u];
        }
    }
    cout << ans << endl;
}