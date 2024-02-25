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
    
    ll count = 0;
    for(ll i = 0; i < N; i++){
        if(i % M == 0){
            count++;
        }
    }

    ll g = gcd(N, count);
    printf("%lld %lld\n", count/g, N/g);
}
