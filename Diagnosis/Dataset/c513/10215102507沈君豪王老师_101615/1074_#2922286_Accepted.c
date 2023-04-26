#include <stdio.h>
#include <string.h>

typedef long long int lli;
const lli M = 1e9 + 7;
lli dp[200][210];

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		char s[200];
		scanf("%s", s);
		lli len = strlen(s), temp;
		lli res = 0;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for(int j = 0; j < len; j ++){
			for(int r = 0 ; r < 210 ; r ++){
				temp = 0;
				for(int k = j; k < len; k ++){
					temp = temp * 10 + (s[k] - '0');
					temp %= 210;
					dp[k + 1][(r + temp) % 210] += dp[j][r];
					dp[k + 1][(r + temp) % 210] %= M;
					if(j != 0){
						dp[k + 1][(r - temp + 210) % 210] += dp[j][r];
						dp[k + 1][(r - temp + 210) % 210] %= M;
					}
				}				
			}
		}
		for(int j = 0 ; j < 210; j ++){
			if(!(j % 2) || !(j % 3) || !(j % 5) || !(j % 7)){
				res += dp[len][j];
				res %= M;
			}
		}
		printf("%lld\n", res);
		
	}
	
	
	return 0;
}