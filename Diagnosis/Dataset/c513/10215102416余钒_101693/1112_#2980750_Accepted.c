#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int T,n;
long long dp[5][1005];
int main() {
	for(int i=0;i<=1000;i++) dp[1][i]=1,dp[2][i]=dp[3][i]=dp[4][i]=0;
	for(int c=2;c<=4;c++){
		for(int i=0;i<=1000;i++)
			for(int j=0;j*c+i<=1000;j++)
				dp[c][j*c+i]+=dp[c-1][i];
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%lld\n",dp[4][n]);
	}
	return 0;
}