#include <stdio.h>
#include <stdlib.h>
#define N 10007

int f(int n,int m,int a, int b)
{
   int dp[n][m],i,j;
   dp[0][0]=1;
   for (i=0;i<=n;i++)
   {
       for (j=0;j<=m;j++)
       {
           if (i+j)
           {
               if (i==0)
                  dp[i][j] = b*dp[i][j-1]%N;
               else if (j==0)
                  dp[i][j] = a*dp[i-1][j]%N;
               else
                  dp[i][j] = (a*dp[i-1][j]+b*dp[i][j-1])%N;
           }
       }
   }
    return dp[n][m];
}
int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int a,b,k,n,m;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        printf("%d\n",f(n,m,a,b));
    }
    return 0;
}
