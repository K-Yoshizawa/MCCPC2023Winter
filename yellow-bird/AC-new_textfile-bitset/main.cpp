#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    scanf("%d %d", &n, &m);

    bitset<300001> arrived, captured;
    while(m--){
        int t,x; scanf("%d %d", &t, &x);

        if(t == 1) arrived.set(x);
        else if(t == 2) arrived.reset(x);
        else captured |= arrived;
    }
    
    for(int i = 1; i <= n; i++) if(captured[i]) printf("%d\n", i);
}
