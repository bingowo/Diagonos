#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,m;
long long dp[40][40] = {0};
int main(void)
{
	for(int i=0;i<=31;i++) dp[i][i] = 1;
	for(int i=0;i<=31;i++){
		for(int j=0;j<i;j++)  
			dp[i][j] = 2*dp[i-1][j]-dp[i-j-1][j]+(1<<(i-j-1));
	}
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n==-1 && m==-1) break;
		printf("%lld\n",dp[n][m]);
	}
	return 0;
}