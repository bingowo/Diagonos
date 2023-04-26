#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N1 1000
#define N2 20
int cmp(const void* e1, const void* e2)
{
	int* p1 = (int*)e1;
	int* p2 = (int*)e2;
	if (*p1 != *p2)
		return *p2 - *p1;
	else
		return cmp(p1 + 1, p2 + 1);
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int N; int a[N1+1][N2+1];
		scanf("%d", &N); int j;
		for (j = 0; j < N; j++)
		{
			int an;
			scanf("%d", &an);
			int k = 0;
			while (an != -1)
			{
				a[j][k] = an;
				k++; scanf("%d", &an);
			}
			a[j][k] = -1;
		}
		qsort(a, N, sizeof(a[0]), cmp);
		for (j = 0; j < N; j++)
		{
			for (int k = 0; a[j][k] != -1; k++)
				printf("%d ",a[j][k]);
			printf("\n");
		}
	}
	return 0;
}