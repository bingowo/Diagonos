#include <stdio.h>
#include <stdlib.h>

int cnt(long long int data)
{
    int number = 0;
    for(int i = 0;i < 64;i++)
        if(data & (1<<i))
        number ++;
    return number;
}

int cmp(const void *a,const void *b)
{
    long long int x,y;
    x = *(long long int *)a;
    y = *(long long int *)b;
    if(cnt(x)==cnt(y))
        return (x-y);
    else
        return (cnt(y)-cnt(x));
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int a = 0;a < T;a++)
    {
        int N;
        scanf("%d",&N);
        long long int n[10000];
        for(int b = 0;b < N;b++)
            scanf("%lld",&n[b]);
        qsort(n,N,8,cmp);
        printf("case #%d:\n",a);
        for(int c = 0;c < N;c++)
            printf("%lld ",n[c]);
        printf("\n");
    }
    return 0;
}
