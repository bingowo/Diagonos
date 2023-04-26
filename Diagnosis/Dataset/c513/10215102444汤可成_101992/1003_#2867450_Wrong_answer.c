#include<stdio.h>
#include<stdlib.h>

int count_one(long long int n)
{
	int num = 0;
	int i = 0;
	for (i = 0; i < 64; i++)
	{
		if (n & (1 << i))
		{
			num++;
		}
	}
	return num;
}

int cmp(const void* a, const void* b)
{
	long long int* pa = (long long int*)a;
	long long int* pb = (long long int*)b;
	if (count_one(*pa) < count_one(*pb)) return 1;
	else if (count_one(*pa) > count_one(*pb)) return -1;
	else return *pa - *pb;
}

int main()
{
	int T = 0;
	scanf("%d", &T);
	int i = 0;
	long long int arr[10000] = { 0 };
	for (i = 0; i < T; i++)
	{
		int n = 0;
		scanf("%d", &n);
		int j = 0;
		for (j = 0; j < n; j++)
		{
			scanf("%lld", &arr[j]);
		}
		qsort(arr, n, sizeof(long long int), cmp);
		printf("case #%d:\n", i);
		for (j = 0; j < n; j++)
		{
			printf("%lld ", arr[j]);
		}
		printf("\n");
	}
	return 0;
}