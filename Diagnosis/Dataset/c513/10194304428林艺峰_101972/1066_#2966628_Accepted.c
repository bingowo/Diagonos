#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dp[30][130];
int main(){
	int i, j, cas, n, p, m, t;
	scanf("%d", &cas);
	for(i = 0; i <cas; ++i){
		scanf("%d%d%d%d", &n, &p, &m, &t);
		memset(dp, 0, sizeof(dp));
		dp[0][p] = 1;
		int time = 1;
		while(time <= m){
			for(j = 1; j <= n; ++j){
				dp[time][j] = dp[time-1][j-1] + dp[time-1][j+1];
			}
			time += 1;
		}
		printf("%d\n", dp[m][t]);
	}
	return 0;
}