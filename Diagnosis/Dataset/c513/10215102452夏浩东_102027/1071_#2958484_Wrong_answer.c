#include <stdio.h>
int f(int n,int m,int a, int b)
{
    int N=10007;
    static int dp[1000][1000]={1};
    int i,j; 
    for (i=0;i<=n;i++) 
        for (j=0;j<=m;j++)
            if (i+j)
                if (i==0) 
                    dp[i][j] = b*dp[i][j-1]%N;
                else if (j==0) 
                    dp[i][j] = a*dp[i-1][j]%N;
                else 
                    dp[i][j] = (a*dp[i-1][j]%N+b*dp[i][j-1]%N)%N;
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
        printf("case #%d:\n",i);
        printf("%d\n",res);
    }
    return 0;
}
