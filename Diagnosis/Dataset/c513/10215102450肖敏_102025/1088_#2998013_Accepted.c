#include <stdio.h>
#define N 41

int main()
{
    int T;
    scanf("%d",&T);
    long long d[N][N];
    d[0][0]=0,d[1][1]=d[1][0]=1;
    for(int x=2;x<=40;x++)
    {
        for(int y=1;y<x;y++)
            d[x][y]=d[x-1][y-1]+d[x-1][y];
        d[x][x]=d[x][0]=1;
    }

    for(int i=0;i<T;i++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("case #%d:\n",i);
        printf("%lld\n",d[n][m]);
    }
    return 0;
}
