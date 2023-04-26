#include<stdio.h>
#include<math.h>
int main()
{
    int dp[32];
    int len,num;
    while(scanf("%d",&len)!=-1 && scanf("%d",&num)!=-1)
    {
        if(num==-1 && len==-1) break;
        for(int i=0;i<=len;i++) dp[i]=0;
        dp[num]=1;
        for(int i=num+1;i<=len;i++)
        {
            dp[i]=2*dp[i-1]+pow(2,i-num-1)-dp[i-num-1];
        }
        printf("%d\n",dp[len]);
    }
}