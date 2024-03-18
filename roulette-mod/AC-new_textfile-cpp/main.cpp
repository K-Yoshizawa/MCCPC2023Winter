#include <iostream>
#include <numeric>
using namespace std;


void solve(int N, int M){
    
    // 0 以上 N 未満の M の倍数の数は 1 + floor((N-1)/M) 個あるので、確率は (1 + floor((N-1)/M))/N
    int numer = 1 + (N-1)/M; // 分子
    int denom = N;           // 分母
    
    // 既約分数で表すために、分子と分母を最大公約数で割る
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
