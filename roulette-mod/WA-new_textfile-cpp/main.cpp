#include <iostream>
#include <numeric>
using namespace std;

void solve(int N, int M){
    
    // 0 以上 N *以下*の M の倍数の数を数えている
    int numer = 1 + N/M;
    int denom = N;
    
    int g = gcd(numer, denom);
    numer /= g;
    denom /= g;

    cout << numer << " " << denom << endl;

}

int main(){
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        int N, M; 
        cin >> N >> M;
        
        solve(N, M);
    }
}
