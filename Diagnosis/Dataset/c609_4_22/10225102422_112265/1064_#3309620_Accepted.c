#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long robin(long long x, long long y)
{
	if (x < y)
	{
		int temp = x;
		x = y;
		y = temp;
	}
	if (y == 0)
		return 0;
	else
		return (x / y) * 4 * y + robin(y, x%y);
}
int main()
{
	long long int x, y;
	scanf("%lld%lld", &x, &y);
	printf("%lld", robin(x,y));
	return 0;
}