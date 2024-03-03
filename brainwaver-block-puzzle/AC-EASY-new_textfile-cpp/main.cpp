#include <iostream>
#include <vector>
using namespace std;

int main(){
    int sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;
    
    string S = "";
    if(gx == 0 && gy == 0) S = "RUULDD";
    else if(gx == 0 && gy == 1) S = "RDLUU";
    else if(gx == 0 && gy == 2) S = "UU";
    else if(gx == 1 && gy == 0) S = "ULDRR";
    else if(gx == 1 && gy == 1) S = "DLURUR";
    else if(gx == 1 && gy == 2) S = "URU";
    else if(gx == 2 && gy == 0) S = "RR";
    else if(gx == 2 && gy == 1) S = "RUR";
    else if(gx == 2 && gy == 2) S = "RUUR";
    
    vector<pair<char,int>> ans;
    for(int i = 0; i < S.size(); i++){
        ans.emplace_back(S[i], 1);
    }

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        auto [d, l] = ans[i];
        cout << d << " " << l << endl;
    }

}
