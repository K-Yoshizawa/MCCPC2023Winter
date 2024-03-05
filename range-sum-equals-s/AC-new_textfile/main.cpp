#include<iostream>
using namespace std;

typedef long long int ll;

const ll MOD = 998244353;

ll get_inv(ll x){
    ll res = 1, n = MOD-2;
    while(n > 0){
        if(n % 2) res = (res * x) % MOD;
        x = (x * x) % MOD;
        n /= 2;
    }
    return res;
}

int main(){
    int N, M, S;
    cin >> N >> M >> S; 

    if(M > S){
        cout << "0" << endl;
    }
    else{
        ll ans = 1;
        
        for(int i = 0; i < M-1; i++){
            ans = (ans * (S-1-i)) % MOD;
            ans = (ans * get_inv(M-1-i)) % MOD;
        }
        
        cout << ans << endl;
    }
}
