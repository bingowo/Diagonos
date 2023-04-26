#include <stdio.h>
#include <stdlib.h>
#define N 10007

int f(int n,int m,int a,int b)
{
    static int i,j,dp[1001][1001]={1};
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        if(i+j)
        {
            if(i==0)
            dp[i][j]=b*dp[i][j-1]%N;
            else if(j==0)
            dp[i][j]=a*dp[i-1][j]%N;
            else dp[i][j]=(a*dp[i-1][j]+b*dp[i][j-1])%N;
        }
    }
    return dp[n][m];
}

int main()
{
    int T,a,b,k,n,m;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        printf("%d\n",f(n,m,a,b));
    }
    return 0;
}