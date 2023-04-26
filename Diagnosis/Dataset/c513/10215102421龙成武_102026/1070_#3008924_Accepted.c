#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int dp[32][32];
int func(int n,int end)
{
    int ans=0;
    if(end==0)
    {
        if(n<=3)
            return pow(2,n-1);
        return func(n-3,0)+func(n-2,1)+func(n-1,0);
    }
    else if(end==1)
    {
        if(n==1)
            return 1;
        else if(n==2)
            return 2;
        ans=2;
        for(int i=1;i<n-1;i++)
        {
            ans+=func(i,0);
        }
        return ans;
    }
}
int main()
{
    int n;
    memset(dp,-1,sizeof(dp));
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)
            break;
        printf("%d\n",func(n+1,0));
    }
    return 0;
}
