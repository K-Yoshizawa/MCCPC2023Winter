#include <iostream>
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
    
    int N = S.size();

    cout << N << endl;
    cout << S << endl;
    
}
