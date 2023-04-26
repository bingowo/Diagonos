#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef long long int LLD;

LLD record[101][21];

LLD abs1(LLD x)
{
    if(x < 0)
        return -x;
    return x;
}

LLD f(LLD n,LLD p,LLD m,LLD t)
{
    if(record[t][m] != -1)
        return record[t][m];
    LLD out;
    if(m == 0 && t == p)
        out = 1;
    else if(abs1(t - p) > m)
        out = 0;
    else if(m == 0 && t != p)
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

int main()
{
    int cas,i;
    scanf("%d",&cas);
    memset(record,-1,sizeof(LLD) * 2121);
    for(i = 0;i < cas;i++)
    {
        int n,p,m,t;
        scanf("%d %d %d %d",&n,&p,&m,&t);
        f(n,p,m,t);
        printf("%llu\n",record[t][m]);
    }
    return 0;
}