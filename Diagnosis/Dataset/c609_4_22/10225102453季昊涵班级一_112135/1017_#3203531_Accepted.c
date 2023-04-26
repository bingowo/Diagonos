#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a, const void *b) {
	int A = *(int *)a;
	int B = *(int *)b;
	if (A > B)
		return 1;
	else
		return -1;
}

int cmp2(const void *a, const void *b) {
	int A = *(int *)a;
	int B = *(int *)b;
	if (A > B)
		return -1;
	else
		return 1;
}

int main() {
	int a[100];
	int i = 0;
	char s;
	s=getchar();
	while ((scanf("%d", &a[i])) != EOF)
		i++;
	if (s == 'A')
		qsort(a, i, sizeof(a[0]), cmp1);
	else
		qsort(a, i, sizeof(a[0]), cmp2);
	for (int j = 0; j < i; j++) {
		if (a[j] == a[j + 1])
			continue;
		printf("%d ", a[j]);
	}
	return 0;
} 