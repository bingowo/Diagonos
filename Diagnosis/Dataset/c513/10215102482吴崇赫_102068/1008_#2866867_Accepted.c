#include<stdio.h>
#include<stdlib.h>
#define N 70
int solve(int x, int y) {
	char d1[N] = { '\0' };
	char d2[N] = { '\0' };
	for (int i = 0;i < 64;++i) {
		d1[i] = d2[i] = '0';
	}
	int right1 =63,right2= 63;
	while (x) {
		d1[right1--] = x %2 + '0';
		x >>= 1;
	}
	while (y) {
		d2[right2--] = y %2 + '0';
		y >>= 1;
	}
	int ans = 0;
	for (int i = 0;i < 64;++i) {
		if (d1[i] != d2[i])ans++;
	}
	return ans;
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", solve(x, y));
	}
	return 0;
}