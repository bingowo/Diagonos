#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
	return (int *)a-(int *)b;
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for (int i = 0; i < n; i++) scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmp);
	long long num=0;
	for(int i = 0; i < n/2; i++)
	{
		num += abs(a[2*i] - a[2*i+1]);
	}
	printf("%lld",num);
	return 0;
}