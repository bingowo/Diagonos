#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 1000000007
int T,l;
long long dp[1005][210];
char s[1005];

long long solve(int x,int y)
{
    long long res=x,ans=1;
    while(y)
    {
        if(y%2)
            ans=(ans*res)%M;
        res=(res*res)%M;
        y>>=1;
    }
    return ans;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1);
        l=strlen(s+1);
        for(int i=0;i<=l;i++)
            for(int j=0;j<210;j++)
                dp[i][j]=0;
        dp[0][0]=1;
        for(int i=0;i<=l;i++)
        {
            int res=0;
            for(int j=i+1;j<=l;j++)
            {
                res=(res*10+s[j]-'0')%210;
                for(int k=0;k<210;k++)
                {
                    dp[j][(k+res)%210]=(dp[j][(k+res)%210]+dp[i][k])%M;
                    dp[j][(k-res+210)%210]=(dp[j][(k-res+210)%210]+dp[i][k])%M;
                }
            }
        }
        long long ans=0;
        for(int i=0;i<=210;i++)
            if(i%2==0||i%3==0||i%5==0||i%7==0)
                ans=(dp[l][i]+ans)%M;
        printf("%lld\n",(ans*solve(2,M-2))%M);
    }
    return 0;
}
