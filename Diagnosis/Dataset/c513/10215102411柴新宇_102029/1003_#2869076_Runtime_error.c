#include <stdio.h>


typedef struct Num {
	long long n;
	int cntO;
} Num;


int a[100], n, temp;

void qsort(int h, int t) {
	if (h >= t)
		return;
	int mid = (h + t) / 2, i = h, j = t, x;
	x = a[mid];
	while (1) {
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i >= j)
			break;
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	a[mid] = a[j];
	a[j] = x;
	qsort(h, j - 1);
	qsort(j + 1, t);
	return;
}

int count_One(long long number) {
	int cnt = 0;
	long long test = 1;
	for (int i = 0; i < 64; i++) {
		if (number & test)
			cnt++;
		test <<= 1;
	}
	return cnt;
}




int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N;
		scanf("%d", &N);
		Num nums[10001];
		for (int j = 0; j < N; j++) {
			scanf("%lld", &nums[j].n);
			long long tmp = nums[j].n;
			nums[j].cntO = count_One(nums[j].n);
		}
		qsort(nums, nums + N);
		printf("case #%d:\n", i);
		for (int j = 0; j < N; j++)
			printf("%d ", nums[j].n);
		printf("\n");
	}
	return 0;
}