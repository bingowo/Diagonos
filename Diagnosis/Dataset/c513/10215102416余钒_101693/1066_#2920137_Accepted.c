#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int T,n,m,p,t;
unsigned long long dp[2][1005];
int main() {
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&p,&m,&t);
		for(int i=1;i<=n;i++) dp[1][i]=dp[0][i]=0;
		dp[0][p]=1;
		for(int i=1;i<=m;i++){
			int nw=i%2,las=(i-1)%2;
			for(int j=1;j<=n;j++) dp[nw][j]=0;
			for(int j=1;j<=n;j++){
				if(j>1) dp[nw][j]+=dp[las][j-1];
				if(j<n) dp[nw][j]+=dp[las][j+1];
			}
		}
		printf("%llu\n",dp[m%2][t]);
	}
	return 0;
}
