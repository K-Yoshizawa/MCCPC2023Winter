#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M; cin >> N >> M;
    vector<int> t(M), x(M);
    map<int, int> dict;
    vector<int> rdict;
    for(int i = 0; i < M; ++i){
        cin >> t[i] >> x[i];
        dict.insert({x[i], 0});
    }

    int idx = 0;
    for(auto [key, val] : dict){
        dict[key] = idx++;
        rdict.push_back(key);
    }

    vector<int> come(dict.size(), -1);
    int last_photo = -1;

    for(int i = 0; i < M; ++i){
        int y = dict[x[i]];
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
    for(int i = 0; i < dict.size(); ++i){
        if(come[i] != -1 and come[i] < last_photo) ans.push_back(rdict[i]);
    }
    for(auto a : ans) cout << a << endl;
}