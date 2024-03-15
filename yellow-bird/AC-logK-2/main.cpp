#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M; cin >> N >> M;
    vector<int> t(M), x(M);
    vector<int> dict(M);
    for(int i = 0; i < M; ++i){
        cin >> t[i] >> x[i];
        dict[i] = x[i];
    }

    sort(dict.begin(), dict.end());
    vector<int> come(M, -1);
    int last_photo = -1;

    for(int i = 0; i < M; ++i){
        int y = lower_bound(dict.begin(), dict.end(), x[i]) - dict.begin();
        switch(t[i]){
            case 1 :
                if(come[y] == -1) come[y] = i;
                break;
            case 2 :
                if(last_photo < come[y]) come[y] = -1;
                break;
            case 3 :
                last_photo = i;
                break;
        }
    }

    vector<int> ans;
    for(int i = 0; i < M; ++i){
        if(come[i] != -1 and come[i] < last_photo) ans.push_back(dict[i]);
    }
    for(auto a : ans) cout << a << endl;
}