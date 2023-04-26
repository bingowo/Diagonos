#include <stdio.h>
#define M 20000
int first[M], next[M], last[M], flag[M], ans[M];

int main()
{
    int N;
    scanf("%d",&N);
    int p0=0, p1=N, i;
    for(i=0; i<N; ++i) {
        scanf("%d",&last[i]);
        if(last[i]) first[--p1] = 1;
    }
    for(i=0; i<N; ++i) 
        next[last[i]?p1++:p0++] = i;
    int k = 0;
    for(i=0; i<N && !flag[k]; ++i) {
        flag[k] = 1;
        ans[i] = first[k];
        k = next[k];
    }
    if(i==N && k==0) for(i=0; i<N; ++i)
        printf("%d%s",ans[i], i<N-1?" ":"\n");
    else printf("-1\n");
    return 0;
}