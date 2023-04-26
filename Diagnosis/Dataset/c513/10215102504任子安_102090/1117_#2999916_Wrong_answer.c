#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long max(long long a,long long b)
{
	return a > b ? a:b; 
}

int main()
{
	long long x0,y0,min_x,min_y,min = LLONG_MAX;
	scanf("%lld %lld",&x0,&y0);
	long long n;
	scanf("%lld",&n);
	long long x[n],y[n],dis;//dis==distance
	for(int i=0;i<n;i++)
	{
		scanf("%lld %lld",&x[i],&y[i]);
		dis = max(abs(x[i]-x0),abs(y[i]-y0));
		if(dis<min)
		{
			min = dis;
			min_x = x[i];
			min_y = y[i];
		}
		else if(dis==min)
		{
			if(x[i]<min_x)
			{
				min_x = x[i];
				min_y = y[i];
			}
			else if(x[i]==min_x && y[i]<min_y)
			{
				min_x = x[i];
				min_y = y[i];
			}
		}
	}
	printf("%lld\n%lld %lld",min,min_x,min_y);
	return 0;
}