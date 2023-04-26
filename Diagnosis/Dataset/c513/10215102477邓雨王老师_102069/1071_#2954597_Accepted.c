#include<stdio.h>
#define M 1000
#define N 10007
long long f(int n,int m,int a,int b)
{ 
   static long long dp[M][M]={1},i,j; 
   for (i=0;i<=n;i++) 
    for (j=0;j<=m;j++)
     if (i+j)
       if (i==0) 
           dp[i][j] = b*dp[i][j-1]%N;
       else if (j==0) 
           dp[i][j] = a*dp[i-1][j]%N;
       else 
           dp[i][j] = (a*dp[i-1][j]+b*dp[i][j-1])%N;
    return dp[n][m];
}
int main(){
	int chance;
	int a,b,k,n,m;
	scanf("%d",&chance);
	int t;
	for(t=0;t<chance;t++){
		scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
		printf("case #%d:\n",t);
		printf("%lld\n",f(n,m,a,b));
	}
}