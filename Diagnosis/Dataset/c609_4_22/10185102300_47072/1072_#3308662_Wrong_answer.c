#include <stdio.h>
#define M 1001
#define N 10007

int f(int n,int m,int a, int b)
{ static int dp[M][M]={1},i,j;
  for (i=0;i<=n;i++) for (j=0;j<=m;j++)
  if (i+j)
    if (i==0)       dp[i][j] = b*dp[i][j-1]%N;
    else if (j==0)  dp[i][j] = a*dp[i-1][j]%N;
    else            dp[i][j] = (a*dp[i-1][j]+b*dp[i][j-1])%N;
  return dp[n][m];
}

int main()
{  int I,T,a,b,n,m;
   for (scanf("%d\n",&T),I=0;I<T;I++)
   {  printf("case #%d:\n",T);
      scanf("%d%d%*d%d%d",&a,&b,&n,&m);
      printf("%d\n",f(n,m,a%N,b%N));
   }
   return 0;
}