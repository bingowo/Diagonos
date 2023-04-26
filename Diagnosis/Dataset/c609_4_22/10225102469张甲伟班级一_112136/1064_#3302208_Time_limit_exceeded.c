#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	long long x,y;
	scanf("%lld%lld",&x,&y);
	if(x==y)
		printf("%lld",2*(x+y));
	else
	{
		long long ans=0;
		while(x+y>0)
		{
			if(x>y)
			{
				ans+=4*y;
				x-=y;
			}
			else if(y>x)
			{
				ans+=4*x;
				y-=x;
			}
			else
			{
				ans+=2*(x+y);
				y=0;x=0;
			}
		}
		printf("%lld",ans);
	}
	return 0;
 } 