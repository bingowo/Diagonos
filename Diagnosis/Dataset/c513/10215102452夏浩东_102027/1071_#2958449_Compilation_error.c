#include <stdio.h>
int f(int n,int m,int a, int b)
{
    int M=1000;
    static int dp[M][M]={1},i,j; 
    for (i=0;i<=n;i++) 
        for (j=0;j<=m;j++)
            if (i+j)
                if (i==0) 
                    dp[i][j] = b*dp[i][j-1]%N;
                else if (j==0) 
                    dp[i][j] = a*dp[i-1][j]%N;
                else 
                    dp[i][j] = (a*dp[i-1][j]+b*dp[i][j-1])%N;
    return dp[n][m];
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        int a,b,k,n,m;
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        int res=f(n,m,a,b);
        printf("case #%d:\n");
        printf("%d\n",res);
    }
    return 0;
}
