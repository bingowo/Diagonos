#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int T;
long long n;
long long dp[60] = {0};
int main(void)
{
	scanf("%d",&T);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 8;
	for(int i=5;i<=50;i++){
		dp[i] = dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4];
	}
	for(int kase=0;kase<T;kase++)
	{
		scanf("%lld",&n);
		printf("case #%d:\n",kase);
		printf("%lld\n",dp[n]);
	}
	return 0;
}