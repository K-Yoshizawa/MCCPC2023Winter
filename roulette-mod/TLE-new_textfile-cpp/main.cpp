#include <iostream>
#include <numeric>
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main(){
    
    int T; scanf("%d", &T);

    for(int i = 0; i < T; i++){
        int N, M;
        scanf("%d %d", &N, &M);
        
        int num = 0, count = 0;
        while(num < N){
            count++;
            num += M;
        }

        int g = gcd(N, count);
        printf("%d %d\n", count/g, N/g);
    }
}
