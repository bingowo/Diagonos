#include <stdio.h>
#include <stdlib.h>

int main()
{
	long long x,y;
	scanf("%lld %lld",&x,&y);
	if(x<0) x=-x;
	if(y<0) y=-y;
	int ans = 0;
	while(1)
	{
		if(x==0 && y==0) break;
		++ans;
		if(abs(x+y)==1) break;
		if(x%2 == y%2)
		{
			printf("-1");
			return 0;
		}
		if(x%2)
		{
			x ^= y;
			y ^= x;
			x ^= y;
		}
		x /= 2;
		long long t1 = (y-1)/2,t2 = (y+1)/2;
		if(x%2 != t1%2) y=t1;
		else y=t2;
	}
	printf("%d",ans);
	return 0;
}