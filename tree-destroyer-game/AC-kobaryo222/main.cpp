#include <bits/stdc++.h>

using namespace std;

template <typename T = int>
struct Edge {
    int from, to;
    T cost;
    int idx;

    Edge() = default;

    Edge(int from, int to, T cost = 1, int idx = -1)
        : from(from)
        , to(to)
        , cost(cost)
        , idx(idx)
    {
    }

    operator int() const { return to; }
};

template <typename T = int>
struct Graph {
    vector<vector<Edge<T>>> g;
    int es;

    Graph() = default;

    explicit Graph(int n)
        : g(n)
        , es(0)
    {
    }

    size_t size() const
    {
        return g.size();
    }

    void resize(int n)
    {
        g.resize(n);
    }

    void add_directed_edge(int from, int to, T cost = 1)
    {
        g[from].emplace_back(from, to, cost, es++);
    }

    void add_edge(int from, int to, T cost = 1)
    {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }

    void read(int M, int padding = -1, bool weighted = false, bool directed = false)
    {
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a += padding;
            b += padding;
            T c = T(1);
            if (weighted)
                cin >> c;
            if (directed)
                add_directed_edge(a, b, c);
            else
                add_edge(a, b, c);
        }
    }

    inline vector<Edge<T>>& operator[](const int& k)
    {
        return g[k];
    }

    inline const vector<Edge<T>>& operator[](const int& k) const
    {
        return g[k];
    }
};

template <typename T = int>
using Edges = vector<Edge<T>>;

int main()
{
    int N;
    cin >> N;
    Graph G(N);
    G.read(N - 1, -1);
    Graph T(N); // 頂点 1 を根とする木(有向グラフ)
    auto dfs = [&](auto& self, int v, int p) -> void {
        for (auto& e : G[v]) {
            if (e.to == p)
                continue;
            T.add_directed_edge(v, e.to);
            self(self, e.to, v);
        }
    };
    dfs(dfs, 0, -1);
    vector<int> x(N - 1);
    for (int i = 0; i < N - 1; i++)
        cin >> x[i];
    vector<bool> used(N, false);
    auto rec = [&](auto& self, int v, int p) -> int {
        if (used[v])
            return 0;
        used[v] = true;
        int ret = 1;
        for (auto& e : T[v]) {
            if (e.to == p)
                continue;
            ret += self(self, e.to, v);
        }
        return ret;
    };
    int64_t ans = 0;
    for (int i = 0; i < N - 1; i++) {
        int64_t v = rec(rec, x[i] - 1, -1);
        ans += v * v;
    }
    cout << ans << endl;
}