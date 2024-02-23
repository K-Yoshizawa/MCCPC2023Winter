#include <stdio.h>

#define NMAX 500050

int come[NMAX];

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    
    for(int i = 1; i <= N; ++i) come[i] = -1;
    int last_photo = -1;
    for(int i = 0; i < M; ++i){
        int t, x;
        scanf("%d %d", &t, &x);
        switch(t){
            case 1 :
                if(come[x] == -1) come[x] = i;
                break;
            case 2 :
                if(last_photo < come[x]) come[x] = -1;
                break;
            case 3 :
                last_photo = i;
                break;
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; ++i){
        if(come[i] != -1 && come[i] < last_photo) ++ans;
    }
    printf("%d\n", ans);
    for(int i = 1; i <= N; ++i){
        if(come[i] != -1 && come[i] < last_photo){
            printf("%d ", i);
        }
    }
    printf("\n");
}