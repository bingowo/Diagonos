#include <stdio.h>
#include <math.h>
int f(int n)
{
	if(n==3) return 7;
	else if(n==4) return 12;
	return f(n-1)+f(n-2)+pow(2,n-4);
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n==-1) break;
		int ans;
		ans=f(n);
		printf("%d\n",ans);
	}
	return 0;
}