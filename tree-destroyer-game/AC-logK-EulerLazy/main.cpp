#include <bits/stdc++.h>
using namespace std;

template<typename Monoid, typename OperatorMonoid = Monoid>
struct LazySegmentTree{
    private:
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function<Monoid(Monoid, OperatorMonoid)>;
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;

    int __Size, __Offset, __ZeroIndex;
    vector<Monoid> __Data;
    vector<OperatorMonoid> __Lazy;
    const F f;
    const G g;
    const H h;
    const Monoid __M1;
    const OperatorMonoid __OM1;

    inline void __Check(int x){
        assert(1 <= x && x <= __Size);
    }

    void __eval(int k){
        if(__Lazy[k] == __OM1) return;
        if(k < __Size){
            __Lazy[k * 2 + 0] = h(__Lazy[k * 2 + 0], __Lazy[k]);
            __Lazy[k * 2 + 1] = h(__Lazy[k * 2 + 1], __Lazy[k]);
        }
        __Data[k] = g(__Data[k], __Lazy[k]);
        __Lazy[k] = __OM1;
    }

    void __update(int ul, int ur, OperatorMonoid x, int left, int right, int cell){
        __eval(cell);
        if(ul <= left && right <= ur){
            __Lazy[cell] = h(__Lazy[cell], x);
            __eval(cell);
        }
        else if(ul < right && left < ur){
            int mid = (left + right) / 2;
            __update(ul, ur, x, left, mid, cell * 2 + 0);
            __update(ul, ur, x, mid, right, cell * 2 + 1);
            __Data[cell] = f(__Data[cell * 2 + 0], __Data[cell * 2 + 1]);
        }
    }

    Monoid __query(int ql, int qr, int left, int right, int cell){
        __eval(cell);
        if(qr <= left || right <= ql){
            return __M1;
        }
        if(ql <= left && right <= qr){
            return __Data[cell];
        }
        int mid = (left + right) / 2;
        Monoid ans_left = __query(ql, qr, left, mid, cell * 2 + 0);
        Monoid ans_right = __query(ql, qr, mid, right, cell * 2 + 1);
        return f(ans_left, ans_right);
    }

    public:
    /**
     * @brief セグメント木を要素数 `Size` で初期化する。
     * @param Size セグメント木の要素数
     * @param Merge 区間取得を行う演算
     * @param Mapping 遅延評価の適用を行う演算
     * @param Composite 遅延評価の合成を行う演算
     * @param Monoid_Identity モノイドの単位元
     * @param OperatorMonoid_Identity 操作モノイドの単位元
     * @param ZeroIndex 0-indexとして扱いたいか (default = `false`)
     */
    LazySegmentTree(int Size, F Merge, G Mapping, H Composite,
    const Monoid &Monoid_Identity, const OperatorMonoid &OperatorMonoid_Identity, bool ZeroIndex = false)
    : f(Merge), g(Mapping), h(Composite), __M1(Monoid_Identity), __OM1(OperatorMonoid_Identity), __ZeroIndex(ZeroIndex){
        __Size = 1;
        while(__Size < Size) __Size <<= 1;
        __Offset = __Size - 1;
        __Data.resize(2 * __Size, __M1);
        __Lazy.resize(2 * __Size, __OM1);
    }

    /**
     * @brief セグメント木を構築する。
     * @attention 必ず `set()` で初期値を代入してから呼び出すこと！
     */
    void build(){
        for(int i = __Offset; i >= 1; --i){
            __Data[i] = f(__Data[i * 2 + 0], __Data[i * 2 + 1]);
        }
    }

    /**
     * @brief セグメント木の初期値を代入する。
     * @param Index 代入先の要素番号 (default = 1-index)
     * @param Value 代入する値
     */
    void set(int Index, Monoid Value){
        __Check(Index + __ZeroIndex);
        __Data[__Offset + Index + __ZeroIndex] = Value;
    }

    /**
     * @brief セグメント木を配列 `Init_Data` で初期化する。
     * @param Init_Data 初期データの配列
     * @param Merge 区間取得を行う演算
     * @param Mapping 遅延評価の適用を行う演算
     * @param Composite 遅延評価の合成を行う演算
     * @param Monoid_Identity モノイドの単位元
     * @param OperatorMonoid_Identity 操作モノイドの単位元
     * @param ZeroIndex 0-indexとして扱いたいか (default = `false`)
     */
    LazySegmentTree(vector<Monoid> &Init_Data, F Merge, G Mapping, H Composite,
    const Monoid &Monoid_Identity, const OperatorMonoid &OperatorMonoid_Identity, bool ZeroIndex = false)
    : f(Merge), g(Mapping), h(Composite), __M1(Monoid_Identity), __OM1(OperatorMonoid_Identity), __ZeroIndex(ZeroIndex){
        __Size = 1;
        while(__Size < (int)Init_Data.size()) __Size <<= 1;
        __Offset = __Size - 1;
        __Data.resize(2 * __Size, __M1);
        __Lazy.resize(2 * __Size, __OM1);
        for(int i = 0; i < (int)Init_Data.size(); ++i){
            __Data[__Size + i] = Init_Data[i];
        }
        build();
    }

    /**
     * @brief 半開区間 `[left, Right)` に対して区間更新クエリを処理する。
     * @param Left 半開区間の左端
     * @param Right 半開区間の右端
     * @param OP 更新操作
     */
    void update(int Left, int Right, OperatorMonoid OP){
        __Check(Left + __ZeroIndex);
        __Check(Right + __ZeroIndex - 1);
        __update(Left + __ZeroIndex, Right + __ZeroIndex, OP, 1, __Size + 1, 1);
    }

    /**
     * @brief 半開区間 `[Left, Right)` に対して区間取得クエリを行う。
     * @param Left 半開区間の左端
     * @param Right 半開区間の右端
     * @return Monoid 取得した結果
     */
    Monoid query(int Left, int Right){
        __Check(Left + __ZeroIndex);
        __Check(Right + __ZeroIndex - 1);
        return __query(Left + __ZeroIndex, Right + __ZeroIndex, 1, __Size + 1, 1);
    }
};

using Vertex = int;

template<typename CostType>
struct Edge{
    public:
    Vertex from, to;
    CostType cost;
    int loc{-1}, id{-1};

    Edge() = default;
    Edge(Vertex from, Vertex to, CostType cost) : from(from), to(to), cost(cost){}

    operator int(){
        return to;
    }
};

template<typename CostType = int>
struct Graph{
    private:
    int m_vertex_size{0}, m_edge_size{0};
    bool m_is_directed{false}, m_is_weighted{false};
    vector<vector<Edge<CostType>>> m_adj;
    vector<int> m_indegree;

    public:
    CostType INF{numeric_limits<CostType>::max() >> 2};

    Graph() = default;

    /**
     * @brief `vertex_size` 頂点 `0` 辺のグラフを作成する。
     * @note `directed` を `true` にすると有向グラフになる。
     * @param vertex_size 頂点数
     * @param directed 有向グラフを作成するか (option, default = `false`)
     */
    Graph(int vertex_size, bool directed = false) : m_vertex_size(vertex_size), m_is_directed(directed){
        m_adj.resize(vertex_size);
        m_indegree.resize(vertex_size, 0);
    }

    /**
     * @brief 頂点 `from` から頂点 `to` に辺を張る。
     * @note `cost` を指定することで重みをつけることができる。
     * @param from 頂点番号
     * @param to 頂点番号
     * @param cost 重み (option, default = `1`)
     */
    void add(Vertex from, Vertex to, CostType cost = 1){
        assert(0 <= from and from < m_vertex_size);
        assert(0 <= to and to < m_vertex_size);
        m_is_weighted |= cost > 1;
        Edge<CostType> e1(from, to, cost);
        e1.loc = m_adj[from].size();
        e1.id = m_edge_size;
        m_adj[from].push_back(e1);
        ++m_edge_size;
        if(m_is_directed){
            ++m_indegree[to];
            return;
        }
        Edge<CostType> e2(to, from, cost);
        e2.loc = m_adj[to].size();
        e2.id = e1.id;
        m_adj[to].push_back(e2);
    }

    /**
     * @brief グラフに `edge_size` 本の辺を入力させる。
     * @param edge_size 入力する辺数
     * @param weighted 重み付き辺か (option, default = `false`)
     * @param zero_index 入力の頂点番号が 0-index か (option, default = `false`)
     */
    void input(int edge_size, bool weighted = false, bool zero_index = false){
        m_is_weighted = weighted;
        for(int i = 0; i < edge_size; ++i){
            Vertex s, t; cin >> s >> t;
            if(!zero_index) --s, --t;
            CostType c = 1;
            if(weighted) cin >> c;
            add(s, t, c);
        }
    }

    /**
     * @brief グラフの頂点数を返す。
     * @return size_t 頂点数
     */
    size_t size(){
        return m_vertex_size;
    }

    /**
     * @brief 頂点 `v` の隣接リストを返す。
     * @param v 頂点番号
     * @return vector<Edge<CostType>>& 頂点 `v` の隣接リスト
     */
    vector<Edge<CostType>> &get_adj(Vertex v){
        return m_adj.at(v);
    }

    vector<Edge<CostType>> &operator[](Vertex v){
        return get_adj(v);
    }
};

template<typename CostType>
struct EulerTour{
    private:
    Graph<CostType> &G;
    vector<int> m_in, m_out;

    void m_dfs(Vertex v, Vertex p, int &t){
        m_in[v] = t++;
        for(auto &e : G[v]){
            if(e.to == p) continue;
            m_dfs(e.to, v, t);
        }
        m_out[v] = t++;
    }

    public:
    /**
     * @brief Construct a new Euler Tour object
     * @param G 木
     * @param Root 根の頂点番号(0-index)
     * @param Offset タイムスタンプの初期値
     */
    EulerTour(Graph<CostType> &G, Vertex Root = 0, int Offset = 0) : G(G){
        m_in.resize(G.size());
        m_out.resize(G.size());
        m_dfs(Root, -1, Offset);
    }

    pair<vector<int>, vector<int>> get(){
        return make_pair(m_in, m_out);
    }
};

struct Monoid{
    long long x{0}, y{1};

    Monoid() = default;
    Monoid(int v) : x(v), y(1) {}

    bool operator==(const Monoid& p){
        return x == p.x && y == p.y;
    }
    
    friend ostream &operator<<(ostream &os, const Monoid &p) {
        return os << "{" << p.x << ", " << p.y << "}";
    }

    static Monoid merge(Monoid &l, Monoid &r){
        Monoid ret;
        ret.x = l.x + r.x;
        ret.y = l.y + r.y;
        return ret;
    }

    static Monoid mapping(Monoid &x, long long y){
        if(y == 100) return x;
        Monoid ret;
        ret.x = x.y * y;
        ret.y = x.y;
        return ret;
    }

    static long long composite(long long x, long long y){
        return y;
    }
};

int main(){
    int N; cin >> N;
    Graph G(N);
    G.input(N - 1);

    EulerTour et(G);
    auto [ins, outs] = et.get();
    vector<Monoid> init(N * 2);
    for(int i = 0; i < N; ++i){
        init[ins[i]] = Monoid(1);
    }
    LazySegmentTree<Monoid, long long> seg(init,
        [&](Monoid l, Monoid r){return Monoid::merge(l, r);},
        [&](Monoid l, long long r){return Monoid::mapping(l, r);},
        [&](long long l, long long r){return Monoid::composite(l, r);},
        Monoid(), 100, true);
    long long ans = 0;
    for(int i = 0; i < N - 1; ++i){
        int x; cin >> x, --x;
        long long v = seg.query(ins[x], outs[x]).x;
        ans += v * v;
        seg.update(ins[x], outs[x], 0);
    }
    cout << ans << endl;
}