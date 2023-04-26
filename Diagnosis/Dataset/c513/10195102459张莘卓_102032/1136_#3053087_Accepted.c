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
    int cnt = p1, pos = 0;
    for(i=0; i<N; ++i) 
        next[last[i]?p1++:p0++] = i;
    for(i=0; i<N; ++i) {
        if(first[pos]) ++cnt;
        pos = next[pos];
    }
    if(cnt < N) printf("-1\n");
    else {
        pos = 0;
        for(i=0; i<N; ++i) {
            printf("%d%c",first[pos],i<N-1?' ':'\n');
            pos = next[pos];
        }
    }
    return 0;
}