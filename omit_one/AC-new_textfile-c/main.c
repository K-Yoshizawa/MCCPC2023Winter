#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, D;
    scanf("%d %d", &N, &D);

    char* S;
    S = (char *)malloc(sizeof(char)*(N+1));
    scanf("%s", S);
    
    char* ans;
    ans = (char *)malloc(sizeof(char)*(D+1));
    
    int index = 0, rem = D-N;
    for(int i = 0; i < N; i++){
        if(S[i] == '0'){
            while(rem-- > 0) ans[index++] = '1';
        }
        ans[index++] = S[i];
    }

    while(rem-- > 0) ans[index++] = '1';
    
    
    printf("%s\n", ans);
    free(S);
    free(ans);
}
