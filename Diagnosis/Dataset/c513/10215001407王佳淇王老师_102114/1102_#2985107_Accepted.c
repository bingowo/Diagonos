#include <stdio.h>
#include <math.h>
int main()
{
	long long n ;
	long long x,y;
	scanf("%lld",&n);//989411878596821217
	long long a = 1;
	while (n>4*a*a)
	{
		a++;
	}
	if (n == 4*a*a)
	{
		x= -a; y= -a;
	}
	else
	{
		if (n>=(2*a)*(2*a-1))
		{
			x = -a; y = a - (n - (2*a)*(2*a-1));
		}
		else if (n>=(2*a-1)*(2*a-1))
		{
			x = a - 1 - (n - (2*a-1)*(2*a-1)); y = a;
		}
		else if (n >=(2*a-2)*(2*a-1))
		{
			x = a - 1; y = -a + 1 + n - (2*a-2)*(2*a-1);
		}
		else
		{
			x = -a + 1 + n - (2*a-2)*(2*a-2); y = -a + 1;
		}
	}
	printf("(%lld,%lld)",x,y);
	return 0;
}
