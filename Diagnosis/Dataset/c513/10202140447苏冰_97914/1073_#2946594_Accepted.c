#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
typedef long long ll;
int a[20];
ll dp[20];
ll dfs(int pos,int s,int limit)
{
    if(pos==-1)
    {
        if(s%9==0) return 0;
        else return 1;
    }
    if(!limit && dp[pos]!=-1) return dp[pos];
    int up=limit?a[pos]:9;
    ll tmp=0;
    for(int i=0;i<=up;i++)
    {
        if(i==9) continue;
        tmp+=dfs(pos-1,s+i,limit && i==a[pos]);
    }
    if(!limit) dp[pos]=tmp;
    return tmp;
}
ll solve(ll x)
{
    int pos=0;
    while(x)
    {
        a[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,0,1);
}
int main()
{
    ll a,b;
    scanf("%lld %lld",&a,&b);
    memset(dp,-1,sizeof(dp));
    long long ans=solve(b)-solve(a-1);
    printf("%lld",ans);
    return 0;
}
