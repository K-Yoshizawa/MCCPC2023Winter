#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M; cin >> N >> M;

    set<int> now, ans;
    for(int i = 0; i < M; ++i){
        int t, x; cin >> t >> x;
        if(t == 1) now.insert(x);
        if(t == 2) now.erase(x);
        if(t == 3){
            if(now.size() > ans.size()){
                for(auto x : ans) now.insert(x);
                swap(now, ans);
            }
            else{
                for(auto x : now) ans.insert(x);
            }
        }
    }
    for(auto x : ans){
        cout << x << endl;
    }
}