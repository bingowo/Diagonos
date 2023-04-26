#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	int T;
	scanf("%d\n", &T);
	int pp = 0;
	while (T--) {
		double out[100] = {0};
		int s = 0;
		int o = 0;
		char in[150];
		gets(in);
		int len = strlen(in);
		for (int i = 0; i < len; i++) {
			if (in[i] == ' ')
				in[i] = 0;
		}
		for (int j = len; j >= 0; j--) {
			while (in[j] != 0)
				j--;
			if (isdigit(in[j + 1]))
				out[o++] = atof(in + j + 1);
			else {
				int k;
				if (j == 0)
					k = j;
				else
					k = j + 1;
				if (in[k] == '+') {
					double temp1 = out[--o];
					double temp2 = out[--o];
					out[o++] = temp1 + temp2;
				} else if (in[k] == '-') {
					double temp1 = out[--o];
					double temp2 = out[--o];
					out[o++] = temp1 - temp2;
				} else if (in[k] == '*') {
					double temp1 = out[--o];
					double temp2 = out[--o];
					out[o++] = temp1 * temp2;
				} else if (in[k] == '/') {
					double temp1 = out[--o];
					double temp2 = out[--o];
					out[o++] = temp1 / temp2;
				}
			}
		}
		printf("case #%d:\n", pp++);
		printf("%.6lf\n", out[0]);
	}

	return 0;
}