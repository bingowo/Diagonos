#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d", &t);
	char s[61];
	for (int z = 0; z < t; z++)
	{
		scanf("%s", s);
		int a[128];
		for (int i = 0; i < 128; i++) a[i] = -1;
		int digit = 0, N = 1, i;
		char* p = s;
		a[*p] = 1;
		while (*++p)//计算每个字符表示的数码
			if (a[*p] == -1)
			{
				a[*p] = digit; 
				digit = digit ? digit + 1 : 2;
				N++;
			}
		if (N < 2) N = 2; //不可能是一进制
		printf("case #%d:\n", z);
		long long ans = 0;
		p = s; 
		while (*p) 
		    ans = ans * N + a[*p++];
		printf("%lld\n", ans);
	}
	return 0;
}