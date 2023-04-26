#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define N 10005

typedef struct {
	int cnt;
	char s[N];
}word;

int main() {
	char input[N] = {0};
	scanf("%s", input);
	if (isalpha(input[strlen(input) - 1]))
		strcat(input, "1");
	word w[N / 2]; 
	int wn = 0, si = 0;
	for (int i = 0; i < strlen(input); ++i) {
		if (isalpha(input[i])) {
			w[wn].s[si++] = input[i];
			w[wn].cnt = 0;
		}
		else {
			w[wn].s[si] = 0;
			w[wn].cnt = w[wn].cnt * 10 + input[i] - '0';
			if (i < strlen(input) - 1 && isalpha(input[i + 1])) {
				wn++;
				si = 0;
			}
		}
	}
	for (int i = 0; i <= wn; ++i) {
		for (int j = 0; j < w[i].cnt; ++j)printf("%s", w[i].s);
	}
	return 0;
}