#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, R;
		scanf("%d %d", &N, &R);
		if (N < 0) {
			printf("-");
			N = -N;
		}
		int out[100];
		int i = 0;
		do {
			out[i++] = N % R;
			N /= R;
		} while (N != 0);
		for (int k = i - 1; k >= 0; k--) {
			if (out[k] < 10)
				printf("%d", out[k]);
			else
				printf("%c", out[k] - 10 + 'A');
		}
		printf("\n");

	}



	return 0;
}