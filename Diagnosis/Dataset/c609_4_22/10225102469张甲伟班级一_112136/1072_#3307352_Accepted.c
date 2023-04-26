#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10007
int T,a,b,k,n,m; 
int dp[10005];
int pow(int x,int y)//快速幂算法 
{
	int res=x,ans=1;
	while(y)
	{
		if(y%2)
			ans=ans*res%N;
		res=res*res%N;
		y/=2;
	}
	return ans;
}
int main()
{
	dp[0]=1;
	for(int i=1;i<=10000;i++)
		dp[i]=dp[i-1]*i%N;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
		a%=N;b%=N;
		printf("case #%d:\n%d\n",i,pow(a,n)*pow(b,m)%N*dp[k]%N*pow(dp[n],N-2)%N*pow(dp[k-n],N-2)%N);//组合数 
	}
}