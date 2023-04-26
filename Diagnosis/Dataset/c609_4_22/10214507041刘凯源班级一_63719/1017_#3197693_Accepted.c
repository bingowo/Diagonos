#include<stdio.h>
#include<stdlib.h>
#define MAXN 105
int a[MAXN], n;
int ans[MAXN], tot;
char mod;
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
int cmp_inti(const void* e1, const void* e2)
{
	return *(int*)e2 - *(int*)e1;
}
void sort1()
{
	for(int i = 1; i <= n; ++i)
	{
		for(int j = i + 1; j <= n; ++j)
		{
			if(a[j] < a[i])
			{
				int c = a[j];
				a[j] = a[i];
				a[i] = c;
			}
		}
	}	
}
void sort2()
{
	for(int i = 1; i <= n; ++i)
	{
		for(int j = i + 1; j <= n; ++j)
		{
			if(a[j] > a[i])
			{
				int c = a[j];
				a[j] = a[i];
				a[i] = c;
			}
		}
	}	
}
int main()
{
	scanf("%c", &mod);
	while(scanf("%d", &a[++n]) != EOF);
	--n;
//	printf("%d", n);
//	int sz = sizeof(a) / sizeof(a[0]);
	if(mod == 'A')
		sort1();
	else
		sort2();
//	for(int i = 1; i <= n; ++i)
//		printf("%d ", a[i]);
	for(int i = 1; i <= n; ++i)
	{
		if(a[i] != a[i - 1])
			ans[++tot] = a[i];
	}
	for(int i = 1; i <= tot; ++i)
		printf("%d ", ans[i]);
	return 0;
}