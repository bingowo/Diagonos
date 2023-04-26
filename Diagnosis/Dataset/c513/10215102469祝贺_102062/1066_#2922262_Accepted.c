#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>



int main()
{	
	int pro;scanf("%d",&pro);
	for(int index=0;index<pro;index++){
		int n,p,m,t;scanf("%d%d%d%d",&n,&p,&m,&t);
		long long dp[m+1][n+2];
		for(int i=0;i<m+1;i++){
		    for(int j=0;j<n+2;j++)dp[i][j]=0;
		}
		dp[0][p]=1;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
			}
		}
		if(t>n)printf("0\n");
		else
		printf("%lld\n",dp[m][t]);
	}
	return 0;
}