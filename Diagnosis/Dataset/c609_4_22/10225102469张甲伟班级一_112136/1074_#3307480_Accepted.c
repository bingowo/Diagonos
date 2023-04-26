#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000000007
int dp[1005][215];//分别为位置和对2*3*5*7（210）的余数 
long long ans;
long long pow(int x,int y){//快速幂 
	long long res=x,ans=1;
	while(y){
		if(y%2) ans=(ans*res)%N;
		res=(res*res)%N;
		y>>=1;
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		char s[1005];
		scanf("%s",s+1);
		int l=strlen(s+1);
		for(int i=0;i<=l;i++) 
			for(int j=0;j<210;j++)
				dp[i][j]=0;
		dp[0][0]=1;
		for(int i=0;i<=l;i++)//遍历位置 
		{
			int res=0;
			for(int j=i+1;j<=l;j++)//对当前位置之后的符号情况做处理
			{
				res=(res*10+s[j]-'0')%210; 
				for(int k=0;k<210;k++)
				{
					dp[j][(k+res)%210]=(dp[j][(k+res)%210]+dp[i][k])%N;
					dp[j][(k-res+210)%210]=(dp[j][(k-res+210)%210]+dp[i][k])%N;
				}
			}
		}
		for(int i=0;i<=210;i++)
			if(i%2==0||i%3==0||i%5==0||i%7==0) 
				ans=(dp[l][i]+ans)%N;
		printf("%lld\n",(ans*pow(2,N-2))%N);//费马小定理 
	}
	return 0;
}