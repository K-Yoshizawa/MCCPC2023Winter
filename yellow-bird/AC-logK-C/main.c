#include <stdio.h>
#include <stdlib.h>

#define MAX 300050

int come[MAX];
int N, M;
int t[MAX], x[MAX], dict[MAX];

int cmp(const void *n1, const void *n2){
    if(*(int*)n1 > *(int*)n2) return 1;
    else if(*(int*)n1 < *(int*)n2) return -1;
    else return 0;
}

int bs(int x){
    int ok = M - 1, ng = -1;
    while(abs(ok - ng) > 1){
        int mid = (ok + ng) / 2;
        if(dict[mid] >= x) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        scanf("%d %d", &t[i], &x[i]);
        dict[i] = x[i];
    }

    qsort(dict, M, sizeof(int), cmp);
    
    for(int i = 0; i < M; ++i) come[i] = -1;
    int last_photo = -1;
    for(int i = 0; i < M; ++i){
        int y = bs(x[i]);
        switch(t[i]){
            case 1 :
                if(come[y] == -1) come[y] = i;
                break;
            case 2 :
                if(last_photo < come[y]) come[y] = -1;
                break;
            case 3 :
                last_photo = i;
                break;
        }
    }

    for(int i = 0; i < M; ++i){
        if(come[i] != -1 && come[i] < last_photo){
            printf("%d\n", dict[i]);
        }
    }
}