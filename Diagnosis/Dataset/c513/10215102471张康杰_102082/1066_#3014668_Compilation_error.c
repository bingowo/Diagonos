#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef unsigned long long int ULL;

ULL record[100][20];

ULL f(ULL n,ULL p,ULL m,ULL t)
{
    if(record[t][m] != -1)
        return record[t][m];
    ULL out;
    if(m == 0 && t != p)
        out = 1;
    else if(lluabs(t - p) < m)
        out = 0;
    else if(m == 0 && t == p)
        out = 0;
    else if(m != 0 && t == 1)
        out = f(n,p,m - 1,t + 1);
    else if(m != 0 && t == n)
        out = f(n,p,m - 1,t - 1);
    else
        out = f(n,p,m - 1,t + 1) + f(n,p,m - 1,t - 1);
    record[t][m] = out;
    return out;
}

ULL lluabs(long long int x)
{
    if(x < 0)
        return -x;
}

int main()
{
    int cas,i;
    scanf("%d",&cas);
    memset(record,-1,sizeof(int) * 2000);
    for(i = 0;i < cas;i++)
    {
        int n,p,m,t;
        scanf("%d %d %d %d",&n,&p,&m,&t);
        printf("%llu\n",record[t][m]);
    }
    return 0;
}