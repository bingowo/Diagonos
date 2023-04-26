#include <stdio.h>
#include <stdlib.h>

int p[26];

int cmp(const void *a, const void *b) {
	char ch1, ch2;
	char *A = *(char (*)[21])a;
	char *B = *(char (*)[21])b;
	while (*A && *B) {
		ch1 = (*A) >= 'a' ? *A - 32 : *A;
		ch2 = (*B) >= 'a' ? *B - 32 : *B;
		if (p[ch1 - 'A'] != p[ch2 - 'A']) {
			return p[ch1 - 'A'] - p[ch2 - 'A'];
		} else {
			A++;
			B++;
		}
	}
	if (*A == 0)
		return -1;
	else
		return 1;
}

int main() {

	char alpha[27];
	while ((scanf("%s", alpha)) != EOF) {
		for (int i = 0; i < 26; i++)
			p[alpha[i] - 'A'] = i;
		getchar();
		char a[100][21];
		char c;
		int count = 0, f = 0, k = 0;
		do {
			c = getchar();
			if (c != ' ' && c != '\n') {
				a[count][k++] = c;
				f = 1;
			} else if (f) {
				a[count][k] = '\0';
				f = 0;
				k = 0;
				count++;
			}
		} while (c != '\n');
		qsort(a, count, sizeof(a[0]), cmp);
		for (int i = 0; i < count; i++)
			printf("%s ", a[i]);
		printf("\n");
	}
	return 0;
}
