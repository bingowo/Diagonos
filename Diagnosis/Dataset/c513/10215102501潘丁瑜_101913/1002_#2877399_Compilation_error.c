#include<stdio.h>
int main()
{
	int T,i;
	char s[61];
	int a[128];
	char* p;
	int digit = 0;
	int N = 1;
	long long ans = 0;
	scanf_s("%d", &T);
	for (i = 0; i < 128; i++) a[i] = -1;
	for (i = 0; i < T; i++)
	{
		scanf_s("%s", s);
		printf("case #%d:\n", i);
		p = s;
		a[*p] = 1;
		while (*++p != 0)
		{
			if (a[*p] == -1)
			{
				a[*p] = digit;
				digit = digit == 0 ? 2 : digit + 1;
				N++;
			}
		}
		if (N < 2)N = 2;
		p = s;
		while (*p)
		{
			ans = ans * N + a[*p++];
		}
		printf("%lld\n", ans);
	}

	return 0;
}