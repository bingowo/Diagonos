#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int cnt;
	int num[50];	
}A;


int cmp(const void *_a, const void *_b) {
	A a = *(A *)_a;
	A b = *(A *)_b;

	int i;
	for (i = 0; i < a.cnt - 1 && i < b.cnt - 1; i++){
		if (a.num[i] != b.num[i])
			return b.num[i] - a.num[i];
	}
	if (a.cnt < b.cnt)
		return 1;
	return -1;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		A a[n];
		int i, j;
		//输入
		for (i = 0; i < n; i++) {
			int res;
			a[i].cnt = 0;
			while (1) {
				scanf("%d", &res);
				a[i].num[a[i].cnt++] = res;
				if (res == -1)
					break;
			}
		}
		
		qsort(a, n, sizeof(a[0]), cmp);
		
		for (i = 0; i < n; i++){
			for (j = 0; j < a[i].cnt - 2; j++)
				printf("%d ", a[i].num[j]);
				
			printf("%d\n", a[i].num[j]);
		}

		
	}
	return 0;
}