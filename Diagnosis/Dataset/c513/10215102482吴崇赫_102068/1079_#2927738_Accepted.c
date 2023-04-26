#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int llu;
int cmp(const void *a, const void *b){ return *(int *)a - *(int *)b;}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		int n, m;
		scanf("%d %d", &n, &m);
		int a[n], newa[(n * (n + 1)) / 2];
		for(int j = 0 ; j < n ; j ++){
			scanf("%d", &a[j]);
			newa[j] = a[j];
		}
		for(int j = 0, idx = n; j < n; j ++){
			for(int k = j + 1; k < n; k ++){
				newa[idx] = a[k] + newa[idx - (n - j)];
				idx ++;
			}
		}
		qsort(newa, n * (n + 1) / 2, sizeof(int), cmp);
		printf("case #%d:\n", i);
		llu l, u, sum = 0;
		for(int j = 0 ; j < m ; j ++){
			scanf("%d %d", &l, &u);
			sum = 0;
			for(int k = l - 1; k < u; k ++){
				sum += newa[k];
			}
			printf("%llu\n", sum);
		}
	}
	
	return 0;
}