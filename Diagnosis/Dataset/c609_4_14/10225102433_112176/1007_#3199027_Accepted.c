#include <stdio.h>
#include <stdlib.h>

int solve(long long n)
{
    int cnt = 0;
    while(n)
    {
        n = n&(n-1);
        cnt++;
    }
    return cnt;
}

typedef struct{long long x,y;}node;

int cmp(const void* a,const void* b)
{
    node *pa = (node*)a;
    node *pb = (node*)b;
    if(pa->y != pb->y)
    {
        if(pa->y > pb->y)
            return -1;
        else
            return 1;
    }
    else
    {
        if(pa->x > pb->x)
            return 1;
        else
            return -1;
    }
}

int main()
{
    int T;scanf("%d",&T);
    for(int i = 0;i < T;i++)
    {
        int n;scanf("%d",&n);
        node a[n];
        for(int j = 0;j < n;j++)
        {
            scanf("%lld",&a[j].x);
            a[j].y = solve(a[j].x);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int j = 0;j < n;j++)
            printf("%lld%c",a[j].x,j == n-1 ? '\n' : ' ');
    }

    return 0;
}