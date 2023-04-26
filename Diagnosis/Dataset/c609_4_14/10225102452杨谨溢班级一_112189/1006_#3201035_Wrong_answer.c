# include<stdio.h>
# include <string.h>
int main()
{
	int t;
	scanf("%d", &t);
	int L[130] = { 0 };
	for (int i = 0; i < t; ++i)
	{
		for (int e = 0; e < 130; ++e)	L[e] = -1;
		int n = 0;
		char str[65];
		scanf("%s", str);
		for (int e = 0,j = 0; j < strlen(str);++j)
		{
			if (L[str[j]]>=0) ;
			else
			{
				int m = (e == 1 ? 0 : e);
				L[str[j]] = (e == 0 ? 1 : m);
				++e;
			}
		}
		for (int e = '0'; e <128; ++e)
		{
			if (L[e] >= 0)  n++;
		}
		//printf("DDD%d\n", n);
		n = n > 2?n:2;
		int out = 0;
		for (int e = 0; e < strlen(str); ++e)
		{
			out = out * n + L[str[e]];
		}
		printf("case #%d:\n%d\n", i, out);
	}
	return 0;
}