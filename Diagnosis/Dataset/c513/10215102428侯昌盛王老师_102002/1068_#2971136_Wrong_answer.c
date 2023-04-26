#include <stdio.h>
#include <math.h>
long long int f(int n,int m)
{
	if(n<m) return 0;
	else if(n==m) return 1;
	return 2*f(n-1,m)-f(n-1-m,m)+pow(2,n-m-1);
}

int main()
{
	int n,m;
	while(scanf("%d",&n)!=-1&&scanf("%d",&m)!=-1)
	{
		long long int ans;
		ans=f(n,m);
		printf("%lld\n",ans);
	}
	return 0;
}