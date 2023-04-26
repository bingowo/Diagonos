#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int trans(char *s) {
	int a = strlen(s);
	int al[26];
	for (int i = 0; i < 26; i++)
		al[i] = 0;
	int out = 0;
	for (int i = 0; i < a; i++) {
		int f = s[i] - 'A';
		if (al[f] != 1) {
			al[f] = 1;
			out++;
		}
	}
	return out;
}

typedef struct {
	char s[21];
	int sum;
} pair;

int cmp(const void *a, const void *b) {
	pair *A = (pair *)a;
	pair *B = (pair *)b;
	if (A->sum == B->sum)
		return
		    strcmp(A->s, B->s);
	else
		return
		    B->sum - A->sum;
}

int main() {
	int T;
	scanf("%d", &T);
	int k = 0;
	while (T--) {
		int n;
		scanf("%d", &n);
		pair in[n];
		for (int i = 0; i < n; i++) {
			scanf("%s", &in[i].s);
			in[i].sum = trans(in[i].s);
		}
		qsort(in, n, sizeof(in[0]), cmp);
		printf("case #%d:\n", k++);
		for (int i = 0; i < n; i++)
			printf("%s\n", in[i].s);

	}




	return 0;
}