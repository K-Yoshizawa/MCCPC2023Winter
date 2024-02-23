#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M; cin >> N >> M;
    
    vector<int> come(N + 1, -1);
    int last_photo = -1;

    for(int i = 0; i < M; ++i){
        int t, x; cin >> t >> x;
        switch(t){
            case 1 :
                if(come[x] == -1) come[x] = i;
                break;
            case 2 :
                if(last_photo < come[x]) come[x] = -1;
                break;
            case 3 :
                last_photo = i;
                break;
        }
    }

    vector<int> ans;
    for(int i = 1; i <= N; ++i){
        if(come[i] != -1 and come[i] < last_photo) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(auto a : ans) cout << a << " ";
    cout << endl;
}