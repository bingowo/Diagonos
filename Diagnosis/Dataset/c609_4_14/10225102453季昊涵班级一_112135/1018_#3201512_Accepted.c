#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	int A = *(int *)a;
	int B = *(int *)b;
	if (A > B)
		return 1;
	else
		return -1;
}

int main() {
	int T;
	scanf("%d", &T);
	int arr[T];
	for (int i = 0; i < T; i++)
		scanf("%d", &arr[i]);
	qsort(arr, T, sizeof(arr[0]), cmp);
	long long int out;
	int i = 0;
	while (i < T) {
		out += (arr[i + 1] - arr[i]);
		i += 2;
	}
	printf("%lld", out);
	return 0;
}