#include <string>
#include <utility>
#include <map>
#include <vector>
#include "testlib.h"
using namespace std;

using af = pair<string, vector<string>>;

af readAns(InStream &is, int N){
    string yn = is.readWord();
    is.readEoln();
    int n = 2 * N + 1;
    vector<string> ret;
    if(yn == "Yes") ret = is.readTokens(n, format("[#.]{%d, %d}", n, n));
    return af(yn, ret);
}

struct UnionFind {
    vector< int > data;

    UnionFind() = default;

    explicit UnionFind(size_t sz) : data(sz, -1) {}

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int find(int k) {
        if(data[k] < 0) return (k);
        return data[k] = find(data[k]);
    }

    int size(int k) {
        return -data[find(k)];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    vector< vector< int > > groups() {
        int n = (int) data.size();
        vector< vector< int > > ret(n);
        for(int i = 0; i < n; i++) {
            ret[find(i)].emplace_back(i);
        }
        ret.erase(remove_if(begin(ret), end(ret), [&](const vector< int > &v) {
            return v.empty();
        }), end(ret));
        return ret;
    }
};

int judge(int N, int M, string S, af &pans, af &jans){
    if(pans.first != jans.first) return -1;
    if(pans.first == "No") return 0;
    int n = 2 * N + 1;
    auto L = pans.second;
    bool ok = L.size() == n;
    for(int i = 0; i < L.size(); ++i) ok &= L[i].size() == n;
    if(!ok) return 1;
    for(int i = 0; i < n; ++i){
        ok &= L[i][0] == '#';
        ok &= L[i][n - 1] == '#';
        ok &= L[0][i] == '#';
        ok &= L[n - 1][i] == '#';
    }
    if(!ok) return 3;
    for(int i = 1; i < n; i += 2){
        for(int j = 1; j < n; j += 2){
            ok &= L[i][j] == '.';
        }
    }
    for(int i = 2; i < n; i += 2){
        for(int j = 2; j < n; j += 2){
            ok &= L[i][j] == '#';
        }
    }
    if(!ok) return 4;
    int y = 1, x = 1;
    map<char, int> dy{{'L', 0}, {'R', 0}, {'U', -1}, {'D', 1}};
    map<char, int> dx{{'L', -1}, {'R', 1}, {'U', 0}, {'D', 0}};
    for(int i = 0; i < M; ++i){
        y += dy[S[i]], x += dx[S[i]];
        ok &= L[y][x] == '.';
    }
    if(!ok) return 5;
    UnionFind uf(N * N);
    for(int y = 1; y < n; y += 2){
        for(int x = 2; x < n; x += 2){
            if(L[y][x] == '#') continue;
            int a = N * (y - 1) / 2 + x / 2, b = a - 1;
            ok &= uf.unite(a, b);
        }
    }
    for(int y = 2; y < n; y += 2){
        for(int x = 1; x < n; x += 2){
            if(L[y][x] == '#') continue;
            int a = N * y / 2 + (x - 1) / 2, b = a - N;
            ok &= uf.unite(a, b);
        }
    }
    if(!ok) return 6;
    if(uf.groups().size() > 1) return 7;
    return 0;
}

int main(int argc, char* argv[]){
    registerTestlibCmd(argc, argv);
    int N = inf.readInt();
    inf.readSpace();
    int M = inf.readInt();
    inf.readEoln();
    string S = inf.readToken(format("[LRUD]{%d, %d}", M, M));
    inf.readEoln();
    inf.readEof();

    af pans = readAns(ouf, N), jans = readAns(ans, N);
    int code = judge(N, M, S, pans, jans);
    switch(code){
        case 0 :
            quitf(_ok, "Accepted [0]\n");
            break;
        case -1 :
            quitf(_wa, "Wrong Answer [-1] : Yes/No\n");
            break;
        case 1 :
            quitf(_wa, "Wrong Answer [1] : Violate Requirement 1\n");
            break;
        case 3 :
            quitf(_wa, "Wrong Answer [3] : Violate Requirement 3\n");
            break;
        case 4 :
            quitf(_wa, "Wrong Answer [4] : Violate Requirement 4\n");
            break;
        case 5 :
            quitf(_wa, "Wrong Answer [5] : Violate Requirement 5\n");
            break;
        case 6 :
            quitf(_wa, "Wrong Answer [6] : Violate Requirement 6\n");
            break;
        case 7 :
            quitf(_wa, "Wrong Answer [7] : Violate Requirement 7\n");
            break;
    }
}