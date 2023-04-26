#include<stdio.h>
int main()
{int T,t,a,b,k,n,m,i,j,v,u;
 int dp[1005][1005];
 scanf("%d",&T);
 for(t=0;t<T;t++)
 {scanf("%d %d %d %d %d ",&a,&b,&k,&n,&m);
  dp[0][0]=1;
  for(j=0;j<=m;j++)
    dp[0][j]=b*dp[0][j-1];
  for(i=0;i<=n;i++)
    dp[i][j]=a*dp[i-1][0];
  for(j=0;j<=m;j++)
  {for(i=0;i<=n;i++)
   dp[i][j]=a*dp[i-1][j]+b*dp[i][j-1];
  }
 }
 v=dp[n][m];
 u=v%10007;
 printf("case #%d:\n",t);
 printf("%d\n",u);
 return 0;
}
