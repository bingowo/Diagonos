#include <stdio.h>
#define N 10007
int f(int n,int m,int a,int b)
{
    static int dp[N][N]={1},i,j;
    for (i=0;i<=n;i++)
    {
        for (j=0;j<=m;j++)
        {
             if (i+j)
             {
                 if (i==0)  dp[i][j] = b*dp[i][j-1]%N;
                 else if (j==0) dp[i][j] = a*dp[i-1][j]%N;
                 else dp[i][j] = ((a*dp[i-1][j])%N+(b*dp[i][j-1])%N)%N;
             }
        }
    }
    return dp[n][m];
}
int main()
{
    int t;
    scanf("%d",&t);
    int a,b,k,n,m;
    for(int z=0;z<t;z++)
    {
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        printf("case #%d:\n",z);
        printf("%d\n",f(n,m,a,b));
    }
    return 0;
}
