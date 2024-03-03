#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long int ll;

struct Dice{
    vector<int> num;
    int top,north,south,west,east,bottom;

    Dice(){
        top = 0, south = 1, east = 2, west = 3, north = 4, bottom = 5;
        num = vector<int>({1,2,3,4,5,6});
    }
    
    void roll(char dir){
        int temp;
        switch(dir){
            case 'U':
                temp = south; south = bottom; bottom = north; north = top; top = temp;
                break;
            case 'R':
                temp = west; west = bottom; bottom = east; east = top; top = temp;
                break;
            case 'D':
                temp = north; north = bottom; bottom = south; south = top; top = temp;
                break;
            case 'L':
                temp = east; east = bottom; bottom = west; west = top; top = temp;
                break;
        }
    };

    int get_num(int idx){
        return num[idx];
    }
};

int main() {
    
    int sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;
    
    vector<pair<char,int>> ans;
    if(sx < gx) ans.emplace_back('R', gx-sx);
    else if(sx > gx) ans.emplace_back('L', sx-gx);

    if(sy < gy) ans.emplace_back('U', gy-sy);
    else if(sy > gy) ans.emplace_back('D', sy-gy);

    Dice dice;
    while(sx != gx){
        if(sx < gx) sx++, dice.roll('R');
        else if(sx > gx) sx--, dice.roll('L');
    }
    while(sy != gy){
        if(sy < gy) sy++, dice.roll('U');
        else if(sy > gy) sy--, dice.roll('D');
    }
    
    string extra = "";
    if(dice.get_num(dice.top) == 1) extra = "RUULDD";
    else if(dice.get_num(dice.south) == 1) extra = "DLUR";
    else if(dice.get_num(dice.east) == 1) extra = "RDLU";
    else if(dice.get_num(dice.west) == 1) extra = "LURD";
    else if(dice.get_num(dice.north) == 1) extra = "URDL";
    
    for(int i = 0; i < extra.size(); i++) ans.emplace_back(extra[i], 1);
    
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        auto [d, l] = ans[i];
        cout << d << " " << l << endl;
    }
}
