#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL long long
int n,dp[20][10005],sum=0;
int w[105],hav[10005];
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]),sum+=w[i];
	for(int i=1;i<=2*sum+1;i++) 
		for(int j=0;j<=n;j++) hav[i]=dp[j][i]=0;
	hav[0]=dp[0][sum+1]=1;
	for(int i=1;i<=n;i++){
		for(int j=-sum;j<=sum;j++){
			if(dp[i-1][j+sum+1]==0) continue;
			dp[i][j+sum+1]=1;
			if(j-w[i]>=-sum) dp[i][j-w[i]+sum+1]=1;
			if(j+w[i]<=sum) dp[i][j+w[i]+sum+1]=1;
		}
		for(int j=-sum;j<=sum;j++) 
			if(dp[i][j+sum+1]){
				if(j<0) hav[-j]=1;
				else hav[j]=1;
			}
	}
	for(int i=1;i<=sum;i++) printf("%d",hav[i]);
	return 0;
}
