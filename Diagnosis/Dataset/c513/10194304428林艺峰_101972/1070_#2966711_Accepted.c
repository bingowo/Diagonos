#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dp[30];
int main(){
	int n, i;
	dp[0] = 0;
	dp[1] = 2;
	dp[2] = 4;
	dp[3] = 7;
	for(i = 4; i <= 20; ++i){
		dp[i] = 2 * dp[i-1] - dp[i-2] + dp[i-3];
	}
	while(scanf("%d", &n)){
		if(n == -1)	break;
		printf("%d\n", dp[n]);
	}
	return 0;
}