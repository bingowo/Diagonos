#include<stdio.h>

int main()
{
	long long x,y,1ans=0;
	scanf("%lld %lld",&x,&y);
	while(x!=0 && y!=0)
	{
		if(x>y)
			ans += 4*y,x-=y;
		else if(x<y)
			ans += 4*x,y-=x;
		else
			ans += 4*x,x-=x,y-=y;
	}
	printf("%lld\n",ans);
	return 0;
}
