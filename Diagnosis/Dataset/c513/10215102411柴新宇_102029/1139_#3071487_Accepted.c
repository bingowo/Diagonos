#include <stdio.h>

int judge(int x) {
	int flag = 1;
	if (x == 0 || x == 1)
		return 1;
	while (x > 1) {
		if (x % 10 == 0 || x % 10 == 1) {
			x /= 10;
		} else {
			flag = -1;
			break;
		}
	}
	return flag;

}

int main() {
	int a;
	scanf("%d", &a);
	int i;
	int ans = -1;
	int cc = 5;
	int mid;
	for (int i = 2; i < 10000; i++) {
		mid = a * i;
		int ans = judge(mid);
		if (ans == 1) {
			printf("%d\n", mid);
			cc = 6;
			break;
		}
	}
//	printf("%d", cc);
	if (cc == 5) {
		printf("%d", ans);
	}

	return 0;
}