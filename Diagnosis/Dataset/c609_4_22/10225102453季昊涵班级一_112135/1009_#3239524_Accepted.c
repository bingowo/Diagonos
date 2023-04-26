#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gcd(int a, int b) {
	int max = a;
	int min = b;
	int c = max % min;
	if (c == 0)
		return min;
	max = min;
	min = c;
	gcd(max, min);
}

int cal(int tem) {
	int out = 0;
	unsigned char temp = tem;
	do {
		int t = temp & 1;
		if (t == 1)
			out++;
	} while (temp = temp >> 1);

	return out;
}

int main() {
	int n;
	scanf("%d", &n);
	char c;
	c = getchar();

	while (n--) {
		char a[121];
		gets(a);
		int sum = 0;
		for (int i = 0; i < strlen(a); i++) {
			int aa = a[i];
			sum += cal(aa);
		}
		int len = strlen(a) * 8;
		int t = gcd(len, sum);
		printf("%d/%d\n", sum / t, len  / t);
	}

	return 0;
}