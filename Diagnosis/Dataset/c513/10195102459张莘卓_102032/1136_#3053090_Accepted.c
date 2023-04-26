#include <stdio.h>

int main()
{
    int N, bin[20000]={0}, cnt=0;
    scanf("%d",&N);
    for(int i=0; i<N; ++i) {
        scanf("%d", &bin[i]);
        if(!bin[i]) ++cnt;
    }
    int p0=0, p1=cnt, next[20001]={0};
    for(int i=0; i<N; ++i)
        next[bin[i]?p1++:p0++] = i;
    int pos = 0;
    for(int i=0; i<N; ++i) 
        if(!bin[pos=next[pos]]) --cnt;
    pos = 0;
    if(cnt) printf("-1\n");
    else for(int i=0; i<N; ++i) {
        pos = next[pos];
        printf("%d%c",bin[pos], i<N-1?' ':'\n');
    }
    return 0;
}