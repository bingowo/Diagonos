#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
long long c,d;
void cal(long long a,long long b,long long r)
{
	c = (-1)*(a+b)+r;
	d = a-b;
}
int main(void)
{
	int num;
	scanf("%x",&num);
	if(num==0) 
	{
		printf("0");
		return 0;
	}
	long long a = 0,b = 0;
	long long mask = (1LL<<62);
	while(mask)
	{
		if(mask & num)
		{
			c = 0,d = 0;
			cal(a,b,1LL);
			a = c,b = d;
		}
		else
		{
			c = 0,d = 0;
			cal(a,b,0LL);
			a = c,b = d;
		}
		mask >>= 1;
	}
	printf("%lld",a);
	if(b==0) ;
	else if(b==-1) printf("-i");
	else if(b==1) printf("+i");
	else if(b>0) printf("%+lldi",b);
	else if(b<0) printf("%lldi",b);
	return 0;
}