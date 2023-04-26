#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GOD(int a, int b) {
	int max = a;
	int min = b;
	int c = max % min;
	if (c == 0)
		return min;
	max = min;
	min = c;
	GOD(max, min);
}

int main() {
	int n;
	scanf("%d", &n);
	char c;
	c = getchar();
	while (n--) {
		char s[121];
		gets(s);
		int out = 0;
		for (int i = 0; i < strlen(s); i++) {
			int tem = s[i];
			if (tem < 0)
				i++;
			unsigned int temp = (unsigned int)tem;
			do {
				int t = temp & 1;
				if (t == 1)
					out++;
			} while (temp = temp >> 1);
		}
		int out1 = 8 * strlen(s);
		int aa = GOD(out1, out);
		printf("%d/%d\n", out / aa, out1 / aa);
	}

	return 0;
}