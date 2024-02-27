#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    getline(cin, S);
    for(auto c : S){
        if(c == ' ' or islower(c)) continue;
        cout << c;
    }
    cout << endl;
}