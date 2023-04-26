#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int T,x;
unsigned long long dp[1005];
int main() {
	dp[0]=0,dp[1]=1,dp[2]=1;
	for(int i=3;i<=74;i++) dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		scanf("%d",&x);
		printf("case #%d:\n%llu\n",c,dp[x]);
	}
	return 0;
}
