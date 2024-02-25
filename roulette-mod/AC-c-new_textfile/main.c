#include <stdio.h>
typedef long long int ll;

// 2つの非負整数 a, b の最大公約数 gcd(a,b) を求める関数
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    
    // N, M は 10^18 までの値を取り得るので long long int で宣言する
    ll N, M;
    scanf("%lld %lld", &N, &M);

    // 0 以上 N 未満の M の倍数は 1 + floor((N-1)/M) 個あるので、確率は (1 + floor((N-1)/M))/N
    ll numer = 1 + (N-1)/M;
    ll denom = N;

    // 既約分数で表すために、分子と分母を最大公約数で割る
    ll g = gcd(numer, denom);
    numer /= g;
    denom /= g;

    printf("%lld %lld\n", numer, denom);
}
