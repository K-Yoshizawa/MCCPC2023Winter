#include <iostream>
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
    
    int N;
    string S = "";
    while((gy-sy) % 4 != 2){
        sy--;
        S += string(1, dir['R']) + string(1, dir['D']) + string(1, dir['L']);
    }
    
    S += string((gy-1) - sy, dir['U']) + string(gx - sx, dir['R']) + dir['U'];
    N = S.size();

    cout << N << endl;
    cout << S << endl;
}
