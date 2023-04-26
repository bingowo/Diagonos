#include <stdio.h>
#include <stdlib.h>
#define A_MAX 2000001

int main()
{
    int M, N;
    scanf("%d %d",&M, &N);
    P **a = (P**)malloc((M+1)*sizeof(P*));
    for(int i=0; i<=M; ++i) {
        a[i] = (P*) malloc((N+1)*sizeof(P));
        a[i][0].val = A_MAX;
        for(int j=1; j<=N; ++j){
            if(i == 0) a[i][j].val = A_MAX;
            else
                scanf("%d",&a[i][j].val);
        }
    }
    a[0][1].val = a[1][0].val = 0;
    for(int i=1; i<=M; ++i)
        for(int j=1; j<=N; ++j)
            if(a[i-1][j].val < a[i][j-1].val){
                a[i][j].val += a[i-1][j].val;
                a[i][j].c = 'D';
            }else {
                a[i][j].val += a[i][j-1].val;
                a[i][j].c = 'R';
            }
            
    int i = M, j = N;
    char route[400];  route[M+N-2] = '\0';
    for(int k=M+N-3; k>=0; --k){
        route[k] = a[i][j].c;
        if(a[i][j].c == 'D') --i;
        else --j;
    }
    printf("%d\n%s\n",a[M][N].val,route);
    for(i=0; i<=M; ++i) free(a[i]);
    free(a);
    return 0;
}