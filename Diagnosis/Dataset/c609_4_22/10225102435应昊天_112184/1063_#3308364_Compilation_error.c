#include<stdio.h>
long long count_step(int n);
int main(){
	int T;
	scanf("%d",&T);
	int n;
	for(int i = 0;i < T;i++){
		scanf("%d",&n);
		printf("case #%d:\n",i); 
		printf("%lld\n",count_step(n));
	}
} 
long long count_step(int n){
	long long dp[n+1] = {0};
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i = 4;i <= n;i++)
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
	return dp[n];
}