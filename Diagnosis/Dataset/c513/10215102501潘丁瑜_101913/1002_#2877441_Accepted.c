#include <stdio.h>
int main()
{
	int T,i,j;
	char s[61]={0};
	int a[128];
	char* p;
	int digit = 0;
	long long ans = 0;
	int N = 1;
	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		scanf("%s", s);
		printf("case #%d:\n", i);
		for (j = 0; j < 128; j++) a[j] = -1;
		ans = 0;
		digit = 0;
		N = 1;
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