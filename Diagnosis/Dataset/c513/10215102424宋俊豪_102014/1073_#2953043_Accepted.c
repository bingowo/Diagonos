#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef long long ll;
int a[25];
ll dp[21][9];

ll dfs(int pos,int tot,int limit,int sum)
{
       if(pos==0&&sum%9) return 1;
       else if(pos==0) return 0;
       if(limit==0&&dp[pos][tot]!=-1)  return dp[pos][tot];
       int up=limit?a[pos]:9;
       ll ans=0;
       for(int i=0;i<=up;i++)
       {   if(i==9) continue;
           ans+=dfs(pos-1,i,limit&&i==a[pos],sum+i);
       }
       if(limit==0) dp[pos][tot]=ans;
       return ans;
}
ll slo(ll x)
{   for(int i=0;i<21;i++)
       for(int j=0;j<9;j++)
          dp[i][j]=-1;
    memset(a,0,sizeof(a));
    int pos=0,max=0;
    while(x)
    {
        a[++pos]=x%10;max+=a[pos];
        x=x/10;
    }
    a[0]=0;
    return dfs(pos,0,1,0);
}
int main()
{
    ll p,b;
    scanf("%lld%lld",&p,&b);
    printf("%lld\n",slo(b)-slo(p-1));
    return 0;
}
