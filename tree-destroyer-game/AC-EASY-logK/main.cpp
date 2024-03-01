#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    for(int i = 0; i < N - 1; ++i){
        int A, B; cin >> A >> B;
    }
    
    vector<int> remain(N + 1, 1);
    int ans = 0;
    for(int i = 0; i < N - 1; ++i){
        int x; cin >> x;
        int cnt = 0;
        for(int j = x; j <= N; ++j){
            cnt += remain[j];
            remain[j] = 0;
        }
        ans += cnt * cnt;
    }
    cout << ans << endl;
}