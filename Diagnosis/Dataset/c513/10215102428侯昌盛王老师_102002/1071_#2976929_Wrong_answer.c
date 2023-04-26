#include <stdio.h>
long long int f(int n,int m,int a,int b)
{
	static int dp[1000][1000]={1},i,j;
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
			if(i+j){
			
				if(i==0) dp[i][j]=b*dp[i][j-1]%10007;
				else if(j==0) dp[i][j]=a*dp[i-1][j]%10007;
				else dp[i][j]=(a*dp[i-1][j]+b*dp[i][j-1])%10007;
			}
	return dp[n][m];
			
}


int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int a,b,k,n,m;
		scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
		long long int ans;
		ans=f(n,m,a,b);
		printf("case #%d:\n",i);
		printf("%lld\n",ans);
	}
	return 0;
}