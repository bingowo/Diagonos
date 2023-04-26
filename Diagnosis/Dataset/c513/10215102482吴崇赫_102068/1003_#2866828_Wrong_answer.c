#include<stdio.h>
#include<stdlib.h>
#define N 10005

int one_cnt(int n) {
	int ans = 0;
	for (int i = 0;i < 64;++i) {
		if (n & 1)ans++;
		n >>= 1;
	}
	return ans;
}


int cmp(const void* a, const void* b) {
	int d1, d2;
	d1 = *(int*)a;d2 = *(int*)b;
	if (one_cnt(d1) != one_cnt(d2))return one_cnt(d1) > one_cnt(d2) ? -1 : 1;
	else return d1 > d2 ? 1 : -1;
}

int main() {
	int T, x = 0;
	scanf("%d\n", &T);
	while (x < T) {
		long long a[N] = { 0 };
		int n;
		scanf("%d\n", &n);
		for (int i = 0;i < n;++i)scanf("%lld", &a[i]);
		qsort(a, n, sizeof(a[0]), cmp);
		printf("case #%d:\n", x++);
		for (int i = 0;i < n;++i)printf("%lld ", a[i]);
		printf("\n");

	}
	return 0;
}