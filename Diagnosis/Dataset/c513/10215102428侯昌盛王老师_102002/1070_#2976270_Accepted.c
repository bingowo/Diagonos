#include <stdio.h>
#include <math.h>
long int f(int n)
{
	if(n==1) return 2;
	if(n==2) return 4;
	if(n==3) return 7;
	return f(n-1)+(f(n-1)-f(n-2)+f(n-3));
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n==-1) break;
		long int ans;
		ans=f(n);
		printf("%ld\n",ans);
	}
	return 0;
}