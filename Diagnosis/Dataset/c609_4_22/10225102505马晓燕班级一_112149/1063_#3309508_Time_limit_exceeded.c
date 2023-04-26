#include <stdio.h>
#define N 50
long long f(int n,int m)
{
	static long long ans[N+1][5]={0};
	if(!ans[n][m])
	{
		if(!n)
			return ans[n][m]=1;
		for(int i=1;i<=4 && i<=n;i++)
		{
			int x = f(n-i,i);
			ans[n][i] += x;
			printf("%d %d\n",x,ans[n][i]);
		}
	}
	return ans[n][m];
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n",f(n,1));
		
	}
}