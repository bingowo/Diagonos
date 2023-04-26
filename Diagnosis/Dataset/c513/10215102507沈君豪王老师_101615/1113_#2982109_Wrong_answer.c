#include <stdio.h> 

typedef unsigned long long int llu;

int main(void)
{
	int k, n;
	scanf("%d %d", &k, &n);
	llu dp[110] = {0, 0, 1};
	for(int i = 3; i <= n; i ++){
		for(int j = 0; j < k; j ++){
			if(n - j - 1 >= 0){
				dp[i] += dp[i - j - 1];
			}else{
				dp[i] += 0;
			}
		}
	}
	printf("%llu", dp[n]);
	
	return 0;
}