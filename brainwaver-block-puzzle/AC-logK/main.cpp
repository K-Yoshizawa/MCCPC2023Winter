#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    vector<pair<char, ll>> ans;

    ll gap_x = (gx - sx + 2000000002LL) % 4;
    switch(gap_x){
        case 0 : break;
        case 1 :
            ans.emplace_back('U', 1);
            ans.emplace_back('R', 1);
            ans.emplace_back('D', 1);
            ans.emplace_back('L', 1);
            break;
        case 2 :
            ans.emplace_back('U', 2);
            ans.emplace_back('L', 1);
            ans.emplace_back('D', 2);
            ans.emplace_back('R', 1);
            break;
        case 3 :
            ans.emplace_back('U', 1);
            ans.emplace_back('L', 1);
            ans.emplace_back('D', 1);
            ans.emplace_back('R', 1);
            break;
    }
    int dx = abs(gx - sx);
    if(dx > 0) ans.emplace_back(gx < sx ? 'L' : 'R', dx);

    int gap_y = (gy - sy + 2000000000LL) % 4;
    switch(gap_y){
        case 0 : break;
        case 1 :
            ans.emplace_back('R', 1);
            ans.emplace_back('U', 1);
            ans.emplace_back('L', 1);
            ans.emplace_back('D', 1);
            break;
        case 2 :
            ans.emplace_back('R', 2);
            ans.emplace_back('U', 1);
            ans.emplace_back('L', 2);
            ans.emplace_back('D', 1);
            break;
        case 3 :
            ans.emplace_back('R', 1);
            ans.emplace_back('D', 1);
            ans.emplace_back('L', 1);
            ans.emplace_back('U', 1);
            break;
    }
    int dy = abs(gy - sy), rev_y = gy < sy;
    if(dy > 0) ans.emplace_back(gy < sy ? 'D' : 'U', dy);
    
    cout << ans.size() << endl;
    for(auto [D, L] : ans){
        cout << D << " " << L << endl;
    }
}