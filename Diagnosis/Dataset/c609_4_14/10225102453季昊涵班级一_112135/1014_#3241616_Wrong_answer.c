#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int flag = 1;
	if (a < 0) {
		a = -a;
		flag = -1;
	}
	int temp[100000];
	int i = 0;
	do {
		temp[i++] = a % 3;
		a /= 3;
	} while (a > 0);
	temp[i + 1] = 0;
	int up = 0;
	int k = 0;
	while (k < i || up) {
		int all;
		if (k < i)
			all = temp[k] + 1 + up;
		else
			all = 1;
		temp[k] = all % 3;
		up = all / 3;
		k++;
	}
	for (int i = 0; i < k; i++) {
		temp[i]--;
		if (flag == -1)
			temp[i] = -1 * temp[i];
		if (temp[i] == -1)
			temp[i] = 2;
	}
	int mov = 0;
	while (b > 1) {
		b /= 3;
		mov++;
	}
	int out = k - 1;
	for (out; out >= mov; out--)
		printf("%d", temp[out]);
	if (mov > 0)
		printf(".");
	for (int i = mov - 1; i >= 0; i--)
		printf("%d", temp[i]);
	return 0;
}