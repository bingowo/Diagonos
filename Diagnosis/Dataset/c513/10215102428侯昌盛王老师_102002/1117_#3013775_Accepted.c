#include <stdio.h>
#include <stdlib.h>
long long maxi(long long int x,long long int y)
{
	if(x>y) return x;
	else return y;
}
int main()
{
	long long int x0,y0;
	scanf("%lld %lld",&x0,&y0);
	int n,i;
	long long max=1e16,x1=1e16,y1=1e16;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		long long int x,y;
		scanf("%lld %lld",&x,&y);
		long long res_x,res_y;
		res_x=llabs(x-x0);
		res_y=llabs(y-y0);
		long long mid=maxi(res_x,res_y);
		//printf("kk=%lld %lld\n",res_x,res_y);
		//printf("mid=%lld\n",mid);
		if(mid<max)
		{
			max=mid;
			x1=x;
			y1=y;
		}
		else if(mid==max)
		{
			if(x<x1)
			{
				x1=x;y1=y;
			}
			else if(y<y1)
			{
				y1=y;x1=x;
			}
		}
	}
	printf("%lld\n",max);
	printf("%lld %lld\n",x1,y1);	
	
	return 0;
}