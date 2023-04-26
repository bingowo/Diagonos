#include <stdio.h>
#include <stdlib.h>

int wei(int a) {
	if (a < 0)
		a = -1 * a;
	int out = 1;
	while (a / 10) {
		out++;
		a /= 10;
	}
	return out;
}

int cmp(const void *a, const void *b) {
	int A = *(int *)a;
	int B = *(int *)b;
	int A1 = wei(A);
	int B1 = wei(B);
	if (A1 == B1) {
		if (A > B)
			return 1;
		else
			return -1;
	} else {
		if (A1 > B1)
			return -1;
		else
			return 1;
	}
}
int a[1000006];

int main() {
	int n = 0, i;
	while (scanf("%d", &a[n]) != EOF)
		n++;
	qsort(a, n, sizeof(a[0]), cmp);
	for (i = 0; i < n; i++)
		printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
	return 0;
}