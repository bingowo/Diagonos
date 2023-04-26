#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double v[26];

int cmp(const void *a, const void *b) {
	char ch1 = *(char *)a;
	char ch2 = *(char *)b;
	char ch11 = ch1 >= 'a' ? ch1 - 32 : ch1;
	char ch22 = ch2 >= 'a' ? ch2 - 32 : ch2;
	if (v[ch11 - 'A'] == v[ch22 - 'A']) {
		if (ch11 == ch22)
			return ch2 - ch1;
		else
			return
			    toupper(ch1) - toupper(ch2);
	} else {
		if (v[ch11 - 'A'] > v[ch22 - 'A'])
			return -1;
		else
			return 1;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	int k = 0;
	while (T--) {
		for (int i = 0; i < 26; i++)
			scanf("%lf", &v[i]);
		char in[101];
		scanf("%s", &in);
		int len = strlen(in);
		qsort(in, len, sizeof(in[0]), cmp);
		printf("case #%d:\n", k++);
		printf("%s\n", in);
	}

	return 0;
}