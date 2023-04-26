#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
    int m,n;
    while(scanf("%d%d",&n,&m)&&m!=-1)
    {
        int dp[32]={1},i;
        for(i=1;i<=n;i++)
        {
            if(i<m)
            dp[i]=2*dp[i-1];
            if(i==m)
            dp[i]=2*dp[i-1]-1;
            if(i>m)
            dp[i]=2*dp[i-1]-dp[i-1-m];
        }
        printf("%d\n",(int)pow(2,n)-dp[n]);
    }
    return 0;
}