#include<stdio.h>
int main()
{int T,t,a,b,k,n,m,i,j,v;
 int dp[1005][1005];
 scanf("%d",&T);
 for(t=0;t<T;t++)
 {scanf("%d %d %d %d %d ",&a,&b,&k,&n,&m);
  for(i=0;i<=1000;i++)
 {for(j=0;j<=1000;j++);
  {if(k==i+j==0) dp[i][j]=1%10007;
   else if(i==0) dp[i][j]=-((b%10007)*(dp[i][j-1]%10007))%10007;
   else if(j==0) dp[i][j]=-((a%10007)*(dp[i-1][j]%10007))%10007;
   else dp[i][j]=-((-((a%10007)*(dp[i-1][j]%10007))%10007)%10007
                 +(-((b%10007)*(dp[i][j-1]%10007))%10007)%10007)%10007;
  }
 }
 v=dp[n][m];
 printf("case #%d:\n",t);
 printf("%d\n",v);
 }
 return 0;
}
