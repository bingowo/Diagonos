#include <stdio.h>
#include <stdlib.h>
int T;

long long a[10010] = {0};

int cal(long long number) {
	int cnt = 0;
	long long test = 1;
	for (int i = 0; i < 64; i++) {
		if (number & test)
			cnt++;
		test <<= 1;
	}
	return cnt;
}

int mycmp(const void *x, const void *y) {
	long long xx = *(long long *)x, yy = *(long long *)y;
	if (cal(xx) == cal(yy)) {
		if (xx > yy)
			return 1;
		else
			return -1;
	} else if (cal(xx) > cal(yy))
		return -1;
	else
		return 1;
}

int main(void) {
	scanf("%d", &T);
	int kase;
	for (kase = 0; kase < T; kase++) {
		int n;
		scanf("%d", &n);
		int i;
		for (i = 0; i < n; i++)
			scanf("%lld", &a[i]);
		qsort(a, n, sizeof(a[0]), mycmp);
		printf("case #%d:\n", kase);
		for (i = 0; i < n; i++)
			printf("%lld ", a[i]);
		printf("\n");
	}
	return 0;
}