#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k,n;
    scanf("%d %d",&k,&n);
    int dp[1001]={0};////dp[n]表示第n项的值
    //特殊情况，也就是前面不足k项的时候
    dp[0]=0;dp[1]=1;
    int lenth,i;
    for(lenth=2;lenth<k;lenth++)
    {
        for(i=lenth-1;i>=0;i--)
            dp[lenth]=dp[lenth]+dp[i];
    }
    if(n>=k)
    {
        for(lenth=k;lenth<n;lenth++)
        {
            for(i=lenth-1;i>=(lenth-k);i--)
                dp[lenth]=dp[lenth]+dp[i];
        }
    }
    printf("%d",dp[n-1]);
}