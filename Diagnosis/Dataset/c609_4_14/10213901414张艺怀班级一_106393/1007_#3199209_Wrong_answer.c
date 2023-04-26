#include <stdio.h>
#include <stdlib.h>
#define MAX 10001
int arr[MAX];
int cmp(const void* a, const void* b);
int cnt_digit(int a);

int main()
{
	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int n = 0;
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[j]);
		}
		qsort(arr, n, sizeof(int), cmp);
		printf("case #%d:\n", i);
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[j]);
		}
		printf("\n");
	}
	return 0;
}

int cmp(const void* a, const void* b)
{
	int a_1 = *(int*)a, b_1 = *(int*)b;
	int size_a = cnt_digit(a_1), size_b = cnt_digit(b_1);
	if (size_a != size_b) {
		return size_b - size_a;
	}
	else {
		return a_1 - b_1;
	}
}

int cnt_digit(int a)
{
	unsigned int b = (unsigned int)a;
	int cnt = 0;
	while (b > 0) {
		cnt += b & 1;
		b >>= 1;
	}
	return cnt;
}