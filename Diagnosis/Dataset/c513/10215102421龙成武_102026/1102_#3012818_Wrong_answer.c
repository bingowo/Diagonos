#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	long long n, i,step,count, x, y;
	scanf("%lld", &n);
	x = y = 0;
	step = 1;
	count = 0;
	if (n >= 1)
	{
		step = (long long)sqrt(n);
		x = step / 2;
		y = x + 1;
		n -= (long long)pow(step, 2);
		count = 1;
	}
	while (n)
	{
		if (n >= step)
		{
			n -= step;
		}
		else
		{
			step = n;
			n = 0;
		}
		if (count % 4 == 0)
		{
			y += step;
		}
		else if (count % 4 == 1)
		{
			x -= step;
			step++;
		}
		else if (count % 4 == 2)
		{
			y -= step;
		}
		else if (count % 4 == 3)
		{
			x += step;
			step++;
		}
		count++;
	}
	printf("(%lld,%lld)", x, y);
	return 0;
}