#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	int *A = *((int **)a);
	int *B = *((int **)b);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		if (A[i] > B[i])
			return -1;
		else if (A[i] < B[i])
			return 1;
		else
			i++;
	}
	if (A[i] == -1)
		return 1;
	if (B[i] == -1)
		return -1;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int **arr;
		int n;
		scanf("%d", &n);
		arr = (int **)malloc(n * sizeof(int *));
		for (int i = 0; i < n; i++) {
			int aa[50];
			int a;
			int l = 0;
			while (scanf("%d", &a) != EOF && a != -1) {
				aa[l++] = a;
			}
			aa[l] = -1;
			int *p = (int *)malloc(sizeof(int) * (l + 1)) ;
			for (int k = 0; k < l + 1; k++)
				*(p + k) = aa[k];
			*(arr + i) = p;
		}
		qsort(arr, n, sizeof(arr[0]), cmp);
		for (int i = 0; i < n; i++) {
			int j = 0;
			while (arr[i][j] != -1 && j < 50) {
				printf("%d ", arr[i][j]);
				j++;
			}
			printf("\n");
		}
		int *p;
		for (int i = 0; i < n; i++) {
			p = arr[i];
			free(p);
		}
		free(arr);
	}
	printf("\n");
	return 0;
}