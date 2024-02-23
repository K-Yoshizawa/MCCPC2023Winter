#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M; cin >> N >> M;

    vector<int> now(N + 1, 0), ans(N + 1, 0);
    for(int i = 0; i < M; ++i){
        int t, x; cin >> t >> x;
        if(t == 1) now[x] = 1;
        if(t == 2) now[x] = 0;
        if(t == 3){
            for(int j = 1; j <= N; ++j){
                if(ans[j] == 0) ans[j] = now[j];
            }
        }
    }
    cout << accumulate(ans.begin(), ans.end(), 0) << endl;
    for(int i = 1; i <= N; ++i){
        if(ans[i]) cout << i << " ";
    }
    cout << endl;
}