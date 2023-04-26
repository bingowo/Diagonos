#include <stdio.h>

int main(void) 
{
	int dp[1001] = {1, };
	for(int i = 1; i <= 4; i ++){
		for(int j = i; j <= 1000; j ++){
			dp[j] += dp[j - i];
		}
	}
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		int n;
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
	
	return 0;
}