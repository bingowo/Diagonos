#include <stdio.h>
#include <stdlib.h>
#define LL long long

LL dfs(LL n, LL p, LL m, LL t)
{
    if(m == 0 && p == t)
        return 1;
    else if (m == 0 && p!=t)
        return 0;
    if(p == 1)
        return dfs(n,p+1,m-1,t);
    if(p == n)
        return dfs(n,p-1,m-1,t);
    return dfs(n,p-1,m-1,t)+dfs(n,p+1,m-1,t);
}

int main()
{
    int cas,i;
    LL n,p,m,t,res;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%lld %lld %lld %lld",&n,&p,&m,&t);
        res = dfs(n,p,m,t);
        printf("%lld\n",res);
    }
    return 0;
}