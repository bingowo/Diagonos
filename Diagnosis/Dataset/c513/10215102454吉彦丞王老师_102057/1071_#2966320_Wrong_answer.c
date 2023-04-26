#include<stdio.h>
int f(int a,int b,int n,int m)
{
    static int dp[1001][1001];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i+j)
            {
                if(i==0)
                {
                    dp[i][j]=b*dp[i][j-1]%10007;
                }
                else if(j==0)
                {
                    dp[i][j]=a*dp[i-1][j]%10007;
                }
                else
                {
                    dp[i][j]=(a*dp[i-1][j]+b*dp[i][j-1])%10007;
                }
            }
        }
    }
    return dp[n][m];
}
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int a,b,k,n,m;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        printf("case #%d:\n",i);
        printf("%d\n",f(a,b,n,m));
    }
    return 0;
}