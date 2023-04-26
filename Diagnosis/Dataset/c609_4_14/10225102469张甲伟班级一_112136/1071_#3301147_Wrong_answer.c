#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	long long x,y; 
	scanf("%lld%lld",&x,&y);
	if((x+y)%2==0)
		printf("-1");
	else
	{
		long long n=1;
		for(int i=1;;i++)
		{
			n*=2;
			if(n>(abs(x)+abs(y)))
			{
				printf("%d",i);
				return 0;
			}
		}
	}
	return 0;
 } 