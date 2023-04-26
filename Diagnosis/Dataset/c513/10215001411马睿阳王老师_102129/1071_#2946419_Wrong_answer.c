#include<stdio.h>
int main()
{int T,t,a,b,k,n,m,i,j,v,u;
 int dp[1005][1005];
 scanf("%d",&T);
 for(t=0;t<T;t++)
 {scanf("%d %d %d %d %d ",&a,&b,&k,&n,&m);
  for(i=0;i<=1000;i++)
 {for(j=0;j<=1000;j++);
  {if(k==i+j==0) dp[i][j]=1;
   else if(i==0) dp[i][j]=b*dp[i][j-1];
   else if(j==0) dp[i][j]=a*dp[i-1][j];
   else dp[i][j]=a*dp[i-1][j]+b*dp[i][j-1];
  }
 }
 v=dp[n][m];
 u=v%10007;
 printf("case #%d:\n",t);
 printf("%d",u);
 }
 return 0;
}
