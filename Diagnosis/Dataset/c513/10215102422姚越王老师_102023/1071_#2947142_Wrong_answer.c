#include<stdio.h>
#define M 1000
#define N 10007
//c(n,k)*a^n*b^m
//(a×b) mod c=(a mod c * b mod c) mod c
//(a+b) mod c=(a mod c+ b mod c) mod c
int f(int n,int m,int a, int b)
{ 
   static int dp[M][M]={1},i,j; 
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

int main()
{
	int T,cas,i,j,a,b,k,n,m;scanf("%d",&T);
	for(cas=0;cas<T;cas++)
	{
		scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);//a%=10007;b%=10007;
	    printf("case #%d:\n%d\n",cas,f(n,m,a,b));
	}
	return 0;
}
