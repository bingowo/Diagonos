#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(int n,int m,int a,int b)
{ static long long int dp[1200][1200]={1},i,j;
for(i=0;i<=n;i++)
  for(j=0;j<=m;j++)
    if(i+j)
      if(i==0)
         dp[i][j]=b*dp[i][j-1]%10007;
       else if(j==0)
         dp[i][j]=a*dp[i-1][j]%10007;
       else
         dp[i][j]=(a*dp[i-1][j]+b*dp[i][j-1])%10007;
return dp[n][m];
}
int main()
{ int t,i,j,a,b,k,m,n;
long long int e;
scanf("%d\n",&t);
for(i=0;i<t;i++)
{ scanf("%d %d %d %d %d\n",&a,&b,&k,&n,&m);
 printf("case #%d:\n",i);
  e=f(n,m,a,b);
 printf("%lld\n",e);
}
}