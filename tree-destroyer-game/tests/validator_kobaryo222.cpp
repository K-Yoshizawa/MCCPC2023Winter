#include "testlib.h"
#include "bits/stdc++.h"

using namespace std;

const int MIN_N = 2;
const int MAX_N = 200'000;

const int MIN_AB = 1;
const int MIN_x = 2;

#line 2 "src/DataStructure/union-find.hpp"

/**
 * @brief Union-Find
 * @docs docs/union-find.md
 */

struct UnionFind {
    vector<int> par;
    UnionFind(int n)
    {
        par.assign(n, -1);
    };
    int find(int x)
    {
        if (par[x] < 0)
            return x;
        else
            return par[x] = find(par[x]);
    }
    int size(int x)
    {
        x = find(x);
        return -1 * par[x];
    }
    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (size(x) < size(y))
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
    vector<int> leaders()
    {
        vector<int> res;
        for (int i = 0; i < (int)par.size(); i++) {
            if (par[i] < 0)
                res.push_back(i);
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
    int N = inf.readInt(MIN_N, MAX_N, "N");
    inf.readEoln();
    vector<int> A(N - 1), B(N - 1);
    UnionFind uf(N);
    for (int i = 0; i < N - 1; i++) {
        A[i] = inf.readInt(MIN_AB, N, "A_i");
        inf.readSpace();
        B[i] = inf.readInt(MIN_AB, N, "B_i");
        inf.readEoln();
        --A[i], --B[i];
        assert(uf.unite(A[i], B[i]));
    }
    assert(uf.leaders().size() == 1);
    vector<int> x(N - 1);
    set<int> xs;
    for (int i = 0; i < N - 1; i++) {
        if (i != 0)
            inf.readSpace();
        x[i] = inf.readInt(MIN_x, N, "x_i");
        assert(!xs.contains(x[i]));
        xs.insert(x[i]);
    }
    inf.readEoln();
    inf.readEof();
}