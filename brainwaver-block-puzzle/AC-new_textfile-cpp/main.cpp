#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    
    map<char,char> dir;
    for(auto c : "LRUD") dir[c] = c;
    
    // sx > gx のとき、グリッドを左右反転してから sx <= gx の場合と同様の処理を行う
    if(sx > gx){
        sx *= -1, gx *= -1;
        swap(dir['L'], dir['R']);
    }

    // sy > gy のとき、グリッドを上下反転してから sy <= gy の場合と同様の処理を行う
    if(sy > gy){
        sy *= -1, gy *= -1;
        swap(dir['U'], dir['D']);
    }
    
    vector<pair<char, int>> ans;
    while((gy-sy) % 4 != 2){
        sy--;
        ans.emplace_back(dir['R'], 1);
        ans.emplace_back(dir['D'], 1);
        ans.emplace_back(dir['L'], 1);
    }
    
    if((gy-1)-sy > 0) ans.emplace_back(dir['U'], (gy-1) - sy);
    if(gx-sx > 0) ans.emplace_back(dir['R'], gx - sx);
    ans.emplace_back(dir['U'], 1);

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        auto [D, L] = ans[i];
        cout << D << " " << L << endl;
    }
    
}
