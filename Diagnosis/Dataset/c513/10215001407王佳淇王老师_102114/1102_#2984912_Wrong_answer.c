#include <stdio.h>
#include <math.h>
int main()
{
	long long n ;
	long long x,y;
	scanf("%d",&n);
	long long a;
	long long b = 5;
	while (n>4*pow(b,2))
	{
		b += 5;
	}
	a = b - 5;
	while (n>4*pow(a,2))
	{
		a++;
	}
	if (n == 4*pow(a,2))
	{
		x= -a; y= -a;
	}
	else
	{
		if (n>=(2*a)*(2*a-1))
		{
			x = -a; y = a - (n - (2*a)*(2*a-1));
		}
		else if (n>=pow((2*a-1),2))
		{
			x = a - 1 - (n - pow((2*a-1),2)); y = a;
		}
		else if (n >=(2*a-2)*(2*a-1))
		{
			x = a - 1; y = -a + 1 + n - (2*a-2)*(2*a-1);
		}
		else
		{
			x = -a + 1 + n - pow((2*a-2),2); y = -a + 1;
		}
	}
printf("(%d,%d)",x,y);
	return 0;
}
