#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int dp[32][32];
int func(int n,int m)
{
    //int ans=0;
    if(n<m)
        dp[n][m]=0;
    else if(n==m)
        dp[n][m]=1;
        //ans=1;
    else if(n>m&&dp[n][m]==-1)
    {
        dp[n][m]=0;
        for(int i=0;i<m;i++)
        {
            dp[n][m]+=func(n-(i+1),m);
        }
        dp[n][m]+=pow(2,n-m);
    }
    return dp[n][m];
    //return ans;
}
int main()
{
    int n,m;
    memset(dp,-1,sizeof(dp));
    while(1)
    {
        scanf("%d %d",&n,&m);
        if(n==-1)
            break;
        printf("%d\n",func(n,m));
    }
    return 0;
}
