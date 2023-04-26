#include<stdio.h>
int f(int n,int m,int a,int b)
{
    int dp[1001][1001],i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i+j==0)
            {
                dp[i][j]=1;
            }
            else
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
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int a,b,k,n,m;
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        a=a%10007;
        b=b%10007;
        printf("case #%d:\n%d\n",i,f(n,m,a,b));
    }
    return 0;
}