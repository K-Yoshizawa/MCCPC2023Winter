#include <iostream>
using namespace std;

int main(){
    int N, D;
    cin >> N >> D;
    
    int rem = D-N;
    string S;
    cin >> S;
    
    string ans = "";
    for(auto c : S){
        if(c == '0') ans += string(rem, '1'), rem = 0;
        ans += c;
    }
    if(rem > 0) ans += string(rem, '1');
    
    cout << ans << endl;
}
