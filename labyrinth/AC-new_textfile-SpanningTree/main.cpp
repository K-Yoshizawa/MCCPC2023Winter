#include <bits/stdc++.h>
using namespace std;


struct unionfind {
    vector<int> par;
    vector<int> sizes;

    unionfind(int n) : par(n),sizes(n,1){
        for(int i = 0; i < n; i++) par[i] = i;
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

typedef pair<int, int> Pos;

int dx[2] = {0,1};
int dy[2] = {1,0};

int main(){
    int N, M;
    cin >> N >> M;
    int len = 2*N+1;

    vector<string> ans(len, string(len, '#'));
    vector used(len, vector<bool>(len));
    
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            if(i*j % 2 == 1) ans[i][j] = '.';
            
            used[i][j] = ((i+1)*(j+1) % 2 == 1 || min({i,j,len-1-i,len-1-j}) == 0); 
        }
    }

    auto pos2idx = [&N](int x, int y) -> int {
        assert(x*y % 2 == 1);
        return (x/2)*N + (y/2);
    };

    auto idx2pos = [&N](int idx) -> Pos {
        assert(0 <= idx && idx < N*N);
        int res_x = 2 * (idx/N) + 1;
        int res_y = 2 * (idx%N) + 1;

        return {res_x, res_y};
    };

    vector<pair<int,int>> edges;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            
            int x = 2*i+1, y = 2*j+1;

            for(int dir = 0; dir < 2; dir++){
                int nx = x + 2*dx[dir], ny = y + 2*dy[dir];
                
                if(min(nx,ny) < 0 || max(nx,ny) >= len) continue;
                edges.emplace_back(pos2idx(x,y),pos2idx(nx,ny));
            }
        }
    }


    string s;
    cin >> s;


    unionfind uf(N*N);
    deque<Pos> deq;
    deq.emplace_back(1,1);
    ans[1][1] = '.';
    used[1][1] = true;
    for(auto c : s){
        auto [nx, ny] = deq.back();

        if(c == 'L') ny--;
        else if(c == 'R') ny++;
        else if(c == 'U') nx--;
        else if(c == 'D') nx++;

        if(min(nx,ny) < 0 || max(nx,ny) >= len || used[nx][ny]){
            cout << "No" << endl;
            return 0;
        }

        deq.emplace_back(nx,ny);
        ans[nx][ny] = '.';
        used[nx][ny] = true;
                    
        if(deq.size() > 3) deq.pop_front();
        if(deq.size() == 3 && nx*ny % 2 == 1){
            auto [px,py] = deq.front();
            int pidx = pos2idx(px,py), nidx = pos2idx(nx,ny);
            
            assert(!uf.same(pidx,nidx));
            
            uf.unite(pidx,nidx);
        }
    }
    
    if(deq.back() != Pos(len-2,len-2)){
        cout << "No" << endl;
        return 0;
    }


    for(auto [u, v] : edges){
        if(uf.same(u,v)) continue;
        
        auto [x, y] = idx2pos(u);
        auto [nx, ny] = idx2pos(v);
        int mx = (x+nx)/2, my = (y+ny)/2;

        ans[x][y] = ans[mx][my] = ans[nx][ny] = '.';
        uf.unite(u,v);
    }
    
    cout << "Yes" << endl;
    for(int i = 0; i < len; i++) cout << ans[i] << endl;
}
