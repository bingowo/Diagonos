# include <stdio.h>
# include <stdlib.h>

typedef struct
{
	long long n;
	int k;  // k代表的是n的二进制中1的个数
}NUM;

int cmp(const void* a, const void* b)
{
	NUM A = *(NUM*)a, B = *(NUM*)b;
	if (A.k == B.k)  return A.n > B.n ? 1 : -1;
	return B.k - A.k;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int cas = 0; cas < t; ++cas)
	{
		int n;
		scanf("%d", &n);
		NUM * L;
		L = (NUM*)malloc(n * sizeof(NUM));
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld", &L[i].n);
			int m = 0,
			long long n1 = L[i].n;
			while (n1>0)
			{
				if ((n1 & 1) == 1) m++;
				n1 = n1 >> 1;
			}
			if (n1 < 0)
			{
				int d = 64;
				while (d--)
				{
					if ((n1 & 1) == 0) m++;
					n1 = n1 >> 1;
				}
				m = 64 - m;
			}
			L[i].k = m;
		}
		qsort(L, n, sizeof(L[0]), cmp);
		printf("case #%d:\n",cas);
		for (int j = 0; j < n; ++j)
		{
			printf("%d ", L[j].n);
		}
		printf("\n");
	}
	return 0;
}