#include<stdio.h>
#include<math.h>
#define MAXN 40
char getnum(int x)
{
	if(x <= x && x <= 9)
	{
		return '0' + x;
	}
	else
	{
		return 'A' + x - 10;
	}
}
int sta[MAXN], pot;
int main()
{
	int t, n, r;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &r);
		pot = 0;
		int naev;
		naev = (n < 0);
		n = abs(n);
		while(n)
		{
			sta[++pot] = abs(n % r);
			n /= r;
		}
		if(naev)
			putchar('-');
		do
		{
			putchar(getnum(sta[pot--]));
		}while(pot);
		putchar('\n');
	}
	return 0;
}