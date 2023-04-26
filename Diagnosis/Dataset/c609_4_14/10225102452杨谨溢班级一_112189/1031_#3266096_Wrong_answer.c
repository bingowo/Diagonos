# include <stdio.h>
# include <stdlib.h>

int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int cases = 0;
	scanf("%d", &cases);
	for (int cas = 0; cas < cases; ++cas)
	{
		int n, m;
		scanf("%d %d\n", &n,& m);
		int* N = (int*)malloc(n * sizeof(n));
		for (int i = 0; i < n; ++i)  scanf("%d", &N[i]);
		int NN = n * (n + 1) / 2; // 新数组的元素个数
		int * SUM = (int*)malloc(NN * sizeof(int));
		int e = 0;
		for (int i = 0; i < n;++i)
		{
			int sum = 0;
			for (int j = i; j < n; ++j)
			{
				sum = sum + N[j];
				SUM[e++] = sum;
			}
		}
		qsort(SUM, NN, sizeof(int), cmp);
		printf("case #%d:\n", cas);
		for (int i = 0; i < m; ++i)
		{
			int L, U;
			scanf("%d %d", &L, &U);
			int ss = 0;
			for (int i = L-1; i <= U-1; ++i)
			{
				ss += SUM[i];
			}
			printf("%d\n",ss);
		}
	}
	return 0;
}