#include <stdio.h>
#define maxlen 100

void big_add(int *dest, int *a, int *b) {
	int carry = 0, temp;
	for (int i = maxlen - 1; i > -1; --i) {
		temp = a[i] + b[i] + carry;
		dest[i] = temp % 10;
		carry = temp / 10;
	}
}

void print(int *dest) {
	int i;
	for (i = 0; i < maxlen; ++i)
		if (dest[i])
			break;
	for (i; i < maxlen; ++i)
		printf("%d", dest[i]);
	printf("\n");
}

int main() {
	int f[121][maxlen];
	f[1][99] = 1;
	for (int i = 2; i <= 120; ++i)
		big_add(f[i], f[i - 1], f[i - 2]);
	int cas, num;
	scanf("%d", &cas);
	for (int i = 0; i < cas; ++i) {
		scanf("%d", &num);
		printf("case #%d:\n", i);
		if (!num)
			printf("0\n");
		else
			print(f[num]);
	}
	return 0;
}