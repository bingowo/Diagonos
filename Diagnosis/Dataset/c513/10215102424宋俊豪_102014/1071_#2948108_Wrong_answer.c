#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define N 10007
#define M 1000
int read(int a,int b,int m,int n)
{
    static int dp[M][M]= {1};
    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
        {
            if(i+j)
            {
                if(i==0)
                    dp[i][j]=b*dp[i][j-1]%N;
                else if(j==0)
                    dp[i][j]=a*dp[i-1][j]%N;
                else
                    dp[i][j]=(a*dp[i-1][j]+b*dp[i][j-1])%N;
            }
        }
    return dp[n][m];
}
int main()
{
    int t,a,b,k,n,m;
    scanf("%d",&t);
    for(int i; i<t; i++)
    {
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        a=a%N;
        b=b%N;
        printf("case #%d\n",i);
        printf("%d\n",read(a,b,m,n));
    }
    return 0;
}
