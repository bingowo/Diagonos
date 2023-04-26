#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	long long x,y; 
	scanf("%lld%lld",&x,&y);
	if(x==0&&y==0)
		printf("0");
	else if((x+y)%2==0)
		printf("-1");
	else
	{
		long long n=1;
		x=abs(x);y=abs(y);
		long long k=x+y;
		for(int i=1;;i++)
		{
			k/=2;
			if(n>k)
			{
				printf("%d",i);
				return 0;
			}
		}
	}
	return 0;
 } 