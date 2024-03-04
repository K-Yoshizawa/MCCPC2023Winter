#include <bits/stdc++.h>
#include <string>
using namespace std;

/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
*/

struct Dice
{
  // int x, y;
  int l, r, f, b, d, u;

  void RollN()
  {
    //  --y;
    int buff = d;
    d = f;
    f = u;
    u = b;
    b = buff;
  }

  void RollS()
  {
    // ++y;
    int buff = d;
    d = b;
    b = u;
    u = f;
    f = buff;
  }

  void RollE() // .o -> o.
  {
    // --x;
    int buff = d;
    d = l;
    l = u;
    u = r;
    r = buff;
  }


  void RollW() // o. -> .o
  {
    //  ++x;
    int buff = d;
    d = r;
    r = u;
    u = l;
    l = buff;
  }
};

typedef long long int ll;

int N;
char D[100];
ll L[100];

int main() {
    int sx,sy,gx,gy;
    scanf("%d %d %d %d", &sx, &sy, &gx, &gy);
    
    if(sx < gx) D[N] = 'R', L[N] = ll(gx)-ll(sx), N++;
    else if(sx > gx) D[N] = 'L', L[N] = ll(sx)-ll(gx), N++;

    if(sy < gy) D[N] = 'U', L[N] = ll(gy)-ll(sy), N++;
    else if(sy > gy) D[N] = 'D',  L[N] = ll(sy)-ll(gy), N++;

    Dice dice;
    dice.u = 1, dice.l = dice.r = dice.b = dice.f = dice.d = 0;
    while(sx != gx){
        if(sx < gx) sx++, dice.RollW();
        else if(sx > gx) sx--, dice.RollE();
    }
    while(sy != gy){
        if(sy < gy) sy++, dice.RollN();
        else if(sy > gy) sy--, dice.RollS();
    }
    
    if(dice.u == 1){
        D[N] = 'R', L[N] = 1, N++;
        D[N] = 'U', L[N] = 2, N++;
        D[N] = 'L', L[N] = 1, N++;
        D[N] = 'D', L[N] = 2, N++;
    }
    else if(dice.b == 1){
        D[N] = 'D', L[N] = 1, N++;
        D[N] = 'L', L[N] = 1, N++;
        D[N] = 'U', L[N] = 1, N++;
        D[N] = 'R', L[N] = 1, N++;
    }
    else if(dice.r == 1){
        D[N] = 'R', L[N] = 1, N++;
        D[N] = 'D', L[N] = 1, N++;
        D[N] = 'L', L[N] = 1, N++;
        D[N] = 'U', L[N] = 1, N++;
    }
    else if(dice.l == 1){
        D[N] = 'L', L[N] = 1, N++;
        D[N] = 'U', L[N] = 1, N++;
        D[N] = 'R', L[N] = 1, N++;
        D[N] = 'D', L[N] = 1, N++;
    }
    else if(dice.f == 1){
        D[N] = 'U', L[N] = 1, N++;
        D[N] = 'R', L[N] = 1, N++;
        D[N] = 'D', L[N] = 1, N++;
        D[N] = 'L', L[N] = 1, N++;
    }
   
    printf("%d\n", N);
    for(int i = 0; i < N; i++) printf("%c %lld\n", D[i], L[i]);
}
