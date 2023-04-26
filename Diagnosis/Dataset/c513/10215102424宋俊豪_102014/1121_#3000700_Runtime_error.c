#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int dp[11][30000]={0};
    int total=0,id,j,n,a[11]={0},ans[1001]={0};
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        total+=a[i];
    }
    dp[1][0]=0;dp[1][1]=a[1];dp[1][2]=-a[1];id=2;
    for(int i=2;i<=n;i++)
    {
        j=0;
        for(int q=0;q<=id;q++)
        {
            dp[i][j++]=dp[i-1][q]+a[i];
            dp[i][j++]=dp[i-1][q]-a[i];
            dp[i][j++]=dp[i-1][q];
        }
        id=j-1;
    }
    for(int i=0;i<=id;i++)
    {
        if(abs(dp[n][i]))
           ans[dp[n][i]]=1;
    }
    for(int i=1;i<=total;i++)
    {
        if(ans[i])
            printf("1");
        else
            printf("0");
    }
    return 0;
}

