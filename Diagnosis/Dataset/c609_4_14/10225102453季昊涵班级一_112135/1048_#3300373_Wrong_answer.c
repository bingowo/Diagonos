#include <stdio.h>
#include <string.h>
#include <math.h>

void sum(int *a, int *b, int *c) {
	int carry = 0;
	int i = 0;
	while (*(a + i) || *(b + i) || carry) {
		int temp = *(a + i) + *(b + i) + carry;
		*(c + i) = temp % 10;
		carry = temp / 10;
		i++;
	}
}


int main() {
	int T;
	scanf("%d", &T);
	int k = 0;
	while (T--) {
		int n;
		scanf("%d", &n);
		if (n == 0) {
			printf("case #%d:\n", k++);
			printf("0\n");
		} else {
			int a[130][100];
			for (int u = 0; u < 130; u++) {
				for (int p = 0; p < 100; p++)
					a[u][p] = 0;
			}
			a[1][0] = 1;
			a[2][0] = 1;
			for (int i = 3; i <= n; i++)
				sum(a[i - 1], a[i - 2], a[i]);
			int y = 99;
			while (a[n][y] == 0)
				y--;
			printf("case #%d:\n", k++);
			for (int j = y; j >= 0; j--)
				printf("%d", a[n][j]);
			printf("\n");
		}
	}
	return 0;
}