#include<stdio.h>
#define N 10007 

int f(int n,int m,int a,int b)
{static long long int dp[1005][1005]={1},i,j;
 for(i=0;i<=n;i++)
 {for(j=0;j<=n;j++)
  {if(i==0)  dp[i][j]=b*dp[i][j-1]%N;
   else if(j==0) dp[i][j]=a*dp[i-1][j]%N;
   else dp[i][j]=(a*dp[i-1][j]+b*dp[i][j-1])%N;
  }
 }
return dp[n][m];
}

int main()
{int T,t,a,b,k,n,m;
 long long int v;
 long long int dp[1005][1005];
 scanf("%d",&T);
for(t=0;t<T;t++)
 {scanf("%d %d %d %d %d ",&a,&b,&k,&n,&m);
 v=dp[n][m];
 printf("case #%d:\n",t);
 printf("%lld\n",v);
 } 
 return 0;
}