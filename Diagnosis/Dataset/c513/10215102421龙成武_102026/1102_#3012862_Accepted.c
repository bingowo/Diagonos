#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long mypow(long long a,long long b)
{
	long long temp = a;
	if (b == 0)
		return 1;
	b--;
	while (b--)
		a = a * temp;
	return a;
}
//万恶的pow函数，还是自己写吧，尤其是超过int的时候
int main()
{
	long long n, i,step,count, x, y;
	scanf("%lld", &n);
	x = y = 0;
	step = 1;
	count = 0;
	if (n >= 1)
	{
		if (n >= mypow(10, 18))
			step = mypow(10, 8) - 1;
		for (;mypow(step,2) < n;step += 2);
		step -= 2;
		x = step / 2;
		y = x + 1;
		n -= mypow(step, 2);
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