#include <stdio.h>
#include<stdlib.h>
long long dp[100000];//方案数 
int  notpri[100000];
int pri[100000],cnt,n;
int main()
{
	int n;
	notpri[1]=1;
	for(int i=2;i*i<=1000;i++)
	{
		if(!notpri[i])
			for(int j=i*i;j<=1000;j+=i)
				notpri[j]=1;
	}
  	dp[0]=1;
  	for(int i=1;i<=1000;i++)
  		if(!notpri[i])
  			pri[++cnt]=i;
  	scanf("%d",&n);
  	for(int j=0;j<=cnt;j++)
  	{
  		for(int i=1;i<=n;i++)
  			if(i-pri[j]>=0)
  				dp[i]+=dp[i-pri[j]];
	  }
	printf("%lld",dp[n]);
  	return 0;
}