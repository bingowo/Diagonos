#include<stdio.h>
#include<math.h>
int main()
{
	int n,m;
	int dp[50]={0};
	while(scanf("%d %d",&n,&m))
	{
		if(n==-1&&m==-1)break;
		dp[0]=1;
		for(int i=1;i<=n;i++)
		{
			if(i<m)
			{
				dp[i]=dp[i-1]*2;
			}
			else if(i==m)
			{
				dp[i]=dp[i-1]*2-1;
			}
			else{
				dp[i]=dp[i-1]*2-dp[i-m-1];
			}
		}
		printf("%lld\n",(int)pow(2,n)-dp[n]);
	}
}