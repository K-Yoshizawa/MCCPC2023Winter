#include <stdio.h>

// ２つの変数を入れ替える関数
void swap(int* a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 2つの非負整数 a, b の最大公約数 gcd(a,b) を求める関数
int gcd(int a, int b) {
    if (a < b) {
        swap(&a, &b);
    }
    if (b == 0) {
        return a;
    }
    int k = a / b;
    return gcd(a - k*b, b);
}

void solve(int N, int M){
    // 0 以上 N 未満の M の倍数は 1 + floor((N-1)/M) 個あるので、確率は (1 + floor((N-1)/M))/N
    int numer = 1 + (N-1)/M;
    int denom = N;

    // 既約分数で表すために、分子と分母を最大公約数で割る
    int g = gcd(numer, denom);
    numer /= g;
    denom /= g;

    printf("%d %d\n", numer, denom);

}

int main(){
    int T;
    scanf("%d", &T);
    
    for(int i = 0; i < T; i++){
        int N, M;
        scanf("%d %d", &N, &M);
        
        solve(N, M);
    }
}
