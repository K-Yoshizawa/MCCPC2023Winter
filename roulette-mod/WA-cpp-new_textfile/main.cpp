#include <iostream>
#include <numeric>
using namespace std;
typedef long long int ll;

int main(){

    ll N, M; 
    cin >> N >> M;
    
    // 0 以上 N 以下の M の倍数を数えている場合
    ll numer = 1 + N/M; 
    ll denom = N;

    ll g = gcd(numer, denom);
    numer /= g;
    denom /= g;

    cout << numer << " " << denom << endl;
}
