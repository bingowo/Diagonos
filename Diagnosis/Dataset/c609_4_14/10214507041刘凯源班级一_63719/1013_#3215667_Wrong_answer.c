#include<stdio.h>
#include<limits.h>
#define int long long
#define abs(x) (x >= 0 ? x : -x)
void poow(int *a, int *b, int c, int d, int r)
{
	int aa = *a;
	int bb = *b;
	*a = (aa * c - bb * d) + r;
	*b = (aa * d + bb * c);
	return;
}
int x;

signed main()
{
	scanf("%llX",&x);
//	printf("%lld\n", x);
	int a = 0, b = 0;
	for(int i = 63; i >= 0; --i)
	{
		poow(&a, &b, -1, 1, (x >> i) & 1);
	}
	if(a && b)
	{
		if(b > 0)
		{
			if(b == 1)
				printf("%d+i", a);
			else
				printf("%d+%di", a, b);
		}
		else
		{
			if(b == -1)
				printf("%d-i", a);
			else
				printf("%d%di", a, b);
		}
	}
	else if(a)
	{
		printf("%d", a);
	}
	else
	{
		if(abs(b) == 1)
			printf("i");
		else
			printf("%di", b);
		
	}
	return 0;
}