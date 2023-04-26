#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define N 10007
#define M 1000
long long  solve(int n,int m,int a, int b)
{
    static long long  dp[M][M]={1},i,j;
    for (i=0;i<=n;i++)
        for (j=0;j<=m;j++)
            if (i+j){
                if (i==0)
                    dp[i][j] = b*dp[i][j-1]%N;
                else if (j==0)
                    dp[i][j] = a*dp[i-1][j]%N;
                else
                    dp[i][j] = (a*dp[i-1][j]+b*dp[i][j-1])%N;
                }
    return dp[n][m];
}
int main()
{
    int T;scanf("%d",&T);
    for(int step=0;step<T;step++){
        printf("case #%d:\n",step);
        int a,b,k,n,m;
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        printf("%lld\n",solve(n,m,a,b));
    }
    return 0;
}
