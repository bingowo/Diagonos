#include <stdio.h>

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		char s[61];
		scanf("%s", s);
		int a[128];
		int i, j, k;
		for (i = 0; i < 128; i++)
			a[i] = -1;

		int digit = 0, N = 0;
		char *p = s;
		a[*p] = 1;
		while (*++p){
			if (a[*p] == -1){
				a[*p] = digit;
				digit = digit ? digit + 1 : 2;
				++N;
			}
		}
		
		if (N < 2)
			N = 2;

		long long ans = 0;
		p = s;
		while (*p)
			ans = ans * N; + a[*p++];
		
		//输出
		printf("case #%d:\n", t);
		printf("%lld\n",ans);
	}
	return 0;
}
