#include <iostream>
#include <numeric>
using namespace std;
typedef long long int ll;

int main(){

    // N, M は 10^18 までの値を取り得るので long long int で宣言する
    ll N, M; 
    cin >> N >> M;
    
    // 0 以上 N 未満の M の倍数の数は 1 + floor((N-1)/M) 個あるので、確率は (1 + floor((N-1)/M))/N
    ll numer = 1 + (N-1)/M; // 分子
    ll denom = N;           // 分母
    
    // 既約分数で表すために、分子と分母を最大公約数で割る
    ll g = gcd(numer, denom);
    numer /= g;
    denom /= g;

    cout << numer << " " << denom << endl;
}
