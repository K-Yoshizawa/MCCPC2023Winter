#include <iostream>
#include <numeric>
using namespace std;
typedef long long int ll;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main(){
    ll N, M;
    scanf("%lld %lld", &N, &M);
    
    ll num = 0, count = 0;
    while(num < N){
        count++;
        num += M;
    }

    ll g = gcd(N, count);
    printf("%lld %lld\n", count/g, N/g);
}
