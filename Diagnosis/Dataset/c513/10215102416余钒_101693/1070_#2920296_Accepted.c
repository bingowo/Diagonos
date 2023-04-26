#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
long long dp[105][2][2];

int main() {
	for(int i=0;i<=100;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++) dp[i][j][k]=0;
	dp[2][1][0]=1,dp[2][1][1]=1,dp[2][0][0]=1,dp[2][0][1]=1;
	
	for(int i=3;i<=20;i++){
		dp[i][0][0]=dp[i-1][1][0]+dp[i-1][0][0];
		dp[i][1][0]=dp[i-1][0][1]+dp[i-1][1][1];
		dp[i][0][1]=dp[i-1][0][0];
		dp[i][1][1]=dp[i-1][1][1]+dp[i-1][0][1];
	}
	while(~scanf("%d",&n)){
		if(n==-1) break;
		if(n>1) printf("%lld\n",dp[n][0][0]+dp[n][0][1]+dp[n][1][0]+dp[n][1][1]);
		else puts("2");
	}
	return 0;
}
