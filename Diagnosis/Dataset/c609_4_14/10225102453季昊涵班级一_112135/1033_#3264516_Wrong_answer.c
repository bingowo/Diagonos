#include <stdio.h>
#include <string.h>

int out[1000086] = {0};
int t[1000086];
int main() {
	int T;
	scanf("%d", &T);
	int tt = 0;
	while (T--) {
		int o = 0;
		char in[100];
		scanf("%s", in);
		int len = strlen(in);
		for (int i = len - 1; i >= 0; i--) {
			int temp = in[i];
			for (int k = 0; k < 8; k++) {
				t[o++] = temp % 2;
				temp = temp / 2;
			}
		}
		int j = 0;
		for (int i = o - 1; i >= 0; i--)
			out[j++] = t[i];
		int sum = 0;
		if (o % 6 != 0)
			o = o + 6 - o % 6;
		int q = 0;
		int ot = 0;
		printf("case #%d:\n", tt++);
		while (q < o) {
			for (int p = 0; p < 6; p++) {
				ot = ot * 2 + out[q++];
			}
			if (ot < 26)
				printf("%c", ot + 'A');
			else if (ot < 52)
				printf("%c", ot - 26 + 'a');
			else if (ot < 62)
				printf("%c", ot - 52 + '0');
			else if (ot == 62)
				printf("+");
			else
				printf("/");
			ot = 0;
			sum++;
		}
		int bu = sum % 4;
		if (bu > 0) {
			for (int k = 0; k < 4 - bu; k++)
				printf("=");
		}
		printf("\n");
	}

	return 0;
}