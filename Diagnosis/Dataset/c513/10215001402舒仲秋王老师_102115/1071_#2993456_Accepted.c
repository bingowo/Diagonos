#include <stdio.h>
#include <stdlib.h>
#include<math.h>
long long int f(int n,int m,int a, int b)
{
   static long long int dp[1001][1001]={1};
   int i,j;
   for (i=0;i<=n;i++)
    for (j=0;j<=m;j++)
     if (i+j)
       if (i==0)
           dp[i][j] = b*dp[i][j-1]%10007;
       else if (j==0)
           dp[i][j] = a*dp[i-1][j]%10007;
       else
           dp[i][j] = (a*dp[i-1][j]+b*dp[i][j-1])%10007;
    return dp[n][m];
}


int main()
{
    int i,N;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        int a,b,k,n,m;
        printf("case #%d:\n",i);
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        printf("%lld\n",f(n,m,a,b));
    }
    return 0;
}
