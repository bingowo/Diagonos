#include <stdio.h>
#include <string.h>

const int N = 1005;



int main() {
	char in[N];
	char out[N];
	int T;
	scanf("%d", &T);
	for (int m = 0; m < T; m++) {
		int i, j, k, tmp;
		scanf("%s", in);
		k = 0;
		int len = strlen(in);
		for (i = 0; i < N; i++) {
			out[i] = '0';
		}
		for (i = len - 1; i > 1; i--) {
			int num = in[i] - '0';
			k=0;
			for (j = 0; j < k || num != 0; j++) {
				tmp = 10 * num + (j < k ? out[j] - '0' : 0);
				out[j] = tmp / 8 + '0';
				num = tmp % 8;
			}
			k = j;
		}
		printf("case #%d:\n0.%s\n", m, out );
	}
	return 0;
}