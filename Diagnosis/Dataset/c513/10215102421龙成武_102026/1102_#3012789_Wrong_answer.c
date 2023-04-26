#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	long long n, i,step,count, x, y;
	scanf("%lld", &n);
	x = y = 0;
	step = 1;
	count = 0;
	while (n)
	{
		if (n >= step)
		{
			n -= step;
		}
		else
		{
			step = n;
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