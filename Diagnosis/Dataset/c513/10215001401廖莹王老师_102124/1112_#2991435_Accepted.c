#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0,i=0,j=0,m=0;
    int dp[1001];
    memset(dp,0,sizeof(int)*1001);dp[0]=1;
    int type[4]={4,3,2,1};
    for(i=0;i<4;i++)
    {
        for(j=type[i];j<=1000;j++)dp[j]=dp[j]+dp[j-type[i]];
    }
    scanf("%d",&n);
    for(i=0;i<n;i++){scanf("%d",&m);printf("%d\n",dp[m]);}


    return 0;
}
