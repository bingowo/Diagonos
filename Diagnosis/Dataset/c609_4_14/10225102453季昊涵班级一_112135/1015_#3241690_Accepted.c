#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a == 0)
		printf("0");
	else {
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
		while (k < i) {
			int all;
			all = temp[k] + 1 + up;
			temp[k] = all % 3;
			up = all / 3;
			k++;
		}
		int out;
		if (up) {
			temp[k] = 1 * flag;
			if (temp[k] == -1)
				temp[k] = 2;
			out = k;
		} else
			out = k - 1;
		for (int i = 0; i < k ; i++) {
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
		int fl = 0;
		for (fl; fl < out; fl++) {
			if (temp[fl] != 0)
				break;
		}
		if (mov > out)
			printf("0");
		for (out; out >= mov; out--)
			printf("%d", temp[out]);
		if (mov > fl)
			printf(".");
		for (int i = mov - 1; i >= fl; i--)
			printf("%d", temp[i]);
	}
	return 0;
}