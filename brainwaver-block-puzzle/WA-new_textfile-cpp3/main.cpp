#include <iostream>
#include <map>
using namespace std;

int main(){
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    map<char,char> dir;
    for(auto c : "LRUD") dir[c] = c;

    if(sx > gx){
        sx *= -1; gx *= -1;
        swap(dir['L'], dir['R']);
    }
    
    if(sy > gy){
        sy *= -1; gy *= -1;
        swap(dir['U'], dir['D']);
    }

    string S = string(max(0, gx - sx - 1), dir['R']) + string(gy - sy, dir['U']) + (gx > sx ? string(1,dir['R']) : "");
    int N = S.size();

    cout << N << endl;
    cout << S << endl;
}
