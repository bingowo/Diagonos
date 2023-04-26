#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int T;
long long dp[80] = {0};
int main(void)
{
	scanf("%d",&T);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for(int i=3;i<80;i++){
		dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
	}
	for(int kase=0;kase<T;kase++)
	{
		int n;
		scanf("%d",&n);
		printf("case %d:\n",kase);
		printf("%lld\n",dp[n]);
	}
	return 0;
}