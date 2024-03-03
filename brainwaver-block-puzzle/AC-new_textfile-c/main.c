#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

const int L = 0;
const int R = 1;
const int U = 2;
const int D = 3;

int N = 0;
char d[200001];
int l[200001];

// c を len 文字追加する
void addc(int len, char c){
    if(len <= 0) return;

    d[N] = c;
    l[N] = len;
    N++;
}

int main(){
    int sx, sy, gx, gy;
    scanf("%d %d %d %d", &sx, &sy, &gx, &gy);
    
    char dir[4] = {'L','R','U','D'};

    // sx > gx のとき、グリッドを左右反転してから sx <= gx の場合と同様の処理を行う
    if(sx > gx){ 
        sx *= -1; gx *= -1;
        dir[L] = 'R'; dir[R] = 'L';
    }

    // sy > gy のとき、グリッドを上下反転してから sy <= gy の場合と同様の処理を行う
    if(sy > gy){ 
        sy *= -1; gy *= -1;
        dir[U] = 'D'; dir[D] = 'U';
    }
    
    while((gy-sy) % 4 != 2){
        sy--;
        addc(1, dir[R]);
        addc(1, dir[D]);
        addc(1, dir[L]);
    }
    
    addc((gy-1)-sy, dir[U]);
    addc(gx-sx, dir[R]);
    addc(1, dir[U]);
    
    printf("%d\n", N);
    for(int i = 0; i < N; i++) printf("%c %d\n", d[i], l[i]);
}
