#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i = a; i < n; i++)

const int MIN_N = 2;
const int MAX_N = 200000;

struct unionfind {
    vector<int> par;
    vector<int> sizes;

    unionfind(int n) : par(n),sizes(n,1){
        rep(i,0,n) par[i] = i;
    }

    int root(int x){
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x,int y){
        x = root(x);
        y = root(y);

        if(x == y) return;

        if(sizes[x] < sizes[y] ) swap(x,y);

        par[y] = x;
        sizes[x] += sizes[y];
        sizes[y] = 0;

        return;
    }

    bool same(int x,int y){
        return root(x) == root(y);
    }

    int size(int x){
        return sizes[root(x)];
    }
};


int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(MIN_N, MAX_N, "N"); inf.readEoln();
    
    unionfind uf(N);
    for(int i = 0; i < N-1; i++){
        int A = inf.readInt(1, N, "A_i"); inf.readSpace();
        int B = inf.readInt(1, N, "B_i"); inf.readEoln();
        A--; B--;
        ensure(A < B && !uf.same(A, B));
        uf.unite(A, B);
    }
    ensure(uf.size(0) == N);

    vector<bool> used(N);
    used[0] = true;
    for(int i = 0; i < N-1; i++){
        int x = inf.readInt(2, N, "x_i");
        x--;
        
        ensure(!used[x]);
        used[x] = true;

        if(i+1 == N-1) inf.readEoln();
        else inf.readSpace();
    }

    inf.readEof();

	return 0;
}
