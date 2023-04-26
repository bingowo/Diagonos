#include<stdio.h>
#include<stdlib.h>
#define abs(a) (a > 0 ? a : -a)
int a[1000005];
int n;
int cmp(void *a, void *b)
{
	int len1 = 0, len2 = 0;
	int *p1 = (int*)a, *p2 = (int*)b;
	int aa = abs(*p1);
	int bb = abs(*p2);
	while(aa)
	{
		aa /= 10;
		++len1;
	}
	while(bb)
	{
		bb /= 10;
		++len2;
	}
	return len1 == len2 ? *p1 - *p2 : len2 - len1;
}
int main()
{
	while(scanf("%d", &a[++n]) != EOF);
	--n;
	qsort(a + 1, n, sizeof(a[0]), cmp);
//	for(int i = 1; i <= n; ++i)
//		printf("%d ", a[i]);
	for(int i = 1; i <= n; ++i)
		printf("%d ", a[i]);
}