#include<stdio.h>
#define N 10007 

long long int f(long long int n,long long int m,long long int a,long long int b)
{static long long int dp[1005][1005]={1},i,j;
 for(i=0;i<=n;i++)
 for(j=0;j<=m;j++)
  if(i==0)  dp[i][j]=b*dp[i][j-1]%N;
   else if(j==0) dp[i][j]=a*dp[i-1][j]%N;
   else dp[i][j]=(a*dp[i-1][j]+b*dp[i][j-1])%N;
return dp[n][m];
}

int main()
{int T,t;
 long long int a,b,n,m,k;
 long long int dp[1005][1005],v;
 scanf("%d",&T);
for(t=0;t<T;t++)
 {scanf("%lld%lld%lld%lld%lld ",&a,&b,&k,&n,&m);
 v=dp[n][m];
 printf("case #%d:\n",t);
 printf("%lld\n",v);
 } 
 return 0;
}