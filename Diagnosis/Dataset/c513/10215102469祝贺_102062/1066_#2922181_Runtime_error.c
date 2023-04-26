#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>



int main()
{	
	int pro;scanf("%d",&pro);
	for(int index=0;index<pro;index++){
		int n,p,m,t;scanf("%d%d%d%d",&n,&p,&m,&t);
		unsigned long long dp[m+1][n+1];
		for(int i=0;i<m+1;i++)memset(dp[i],0,sizeof(unsigned long long)*(m+1));
		dp[0][p]=1;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(dp[i-1][j]!=0){
					dp[i][j]=0;
					if(j==1)dp[i][j+1]++;
					else if(j==n)dp[i][j-1]++;
					else {
						dp[i][j+1]++;dp[i][j-1]++;
					}
				}
			}
		}
		printf("%llu\n",dp[m][t]);
	}
	return 0;
}