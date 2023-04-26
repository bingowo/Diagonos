#include <stdio.h>
#include <stdlib.h>

int A[1001] = {0};

int cmp(const void *a, const void *b) {
	int A1 = *(int *)a;
	int B1 = *(int *)b;
	if (A[A1] == 0 && A[B1] == 0)
		return A1 - B1;
	else
		return A[B1] - A[A1];
}

int main() {
	int B[501] = {0};
	int a, b;
	scanf("%d", &a);
	for (int i = a; i >= 1; i--) {
		int t;
		scanf("%d", &t);
		A[t] = i;
	}
	scanf("%d", &b);
	for (int k = 0; k < b; k++)
		scanf("%d", &B[k]);
	qsort(B, b, sizeof(B[0]), cmp);
	for (int i = 0; i < b; i++)
		printf("%d ", B[i]);
	printf("\n");
	return 0;
}