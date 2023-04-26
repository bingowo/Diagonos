#include <stdio.h>
#include <stdlib.h>

typedef struct {
	long long int a;
	int b;
} Point;

int cmp(const void *a, const void *b) {
	Point *A = (Point *)a;
	Point *B = (Point *)b;
	if (A->b == B->b) {
		if (A->a > B->a)
			return 1;
		else
			return -1;
	} else {
		if (A->b > B->b)
			return -1;
		else
			return 1;
	}
}

int sum(long long int a) {
	unsigned long long int temp = a;
	int out = 0;
	do {
		int i = temp & 1;
		if (i == 1)
			out++;
	} while (temp = temp >> 1);
	return out;
}

int main() {
	int T;
	scanf("%d", &T);
	int k = 0;
	while (T--) {
		int N;
		scanf("%d", &N);
		Point arr[N];
		for (int i = 0; i < N; i++) {
			scanf("%lld", &arr[i].a);
			arr[i].b = sum(arr[i].a);
		}
		qsort(arr, N, sizeof(arr[0]), cmp);
		printf("case #%d:\n", k);
		k++;
		for (int i = 0; i < N; i++)
			printf("%lld ", arr[i].a);
		printf("\n");
	}
	return 0;
}