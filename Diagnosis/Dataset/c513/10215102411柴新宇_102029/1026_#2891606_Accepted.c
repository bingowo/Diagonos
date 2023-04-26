#include <stdio.h>
#include <math.h>


int cmp(const void *a, const void *b) {
	int ta = *(int *)a;
	int tb = *(int *)b;

	if (ta < tb)
		return -1;

	else
		return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	int a[100001] = {0};
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(a, n, sizeof(a[0]), cmp);
	int sum = 0;
	for (int i = 0; i < n; i += 2)
		sum += a[i + 1] - a[i];
	printf("%d\n", sum);
	return 0;
}