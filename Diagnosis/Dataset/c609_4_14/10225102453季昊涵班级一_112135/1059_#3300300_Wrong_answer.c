#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int sign;
	int c;
	char it[101];
	char db[101];
} Node;

int cmp(const void *a, const void *b) {
	Node *A = (Node *)a;
	Node *B = (Node *)b;
	if (A->sign == B->sign) {
		if (strlen(A->it) == strlen(B->it)) {
			if (!strcmp(A->it, B->it)) {
				return A->sign * strcmp(A->db, B->db);
			} else
				return A->sign * strcmp(A->it, B->it);
		} else
			return A->sign * (strlen(A->it) - strlen(B->it));
	} else
		return A->sign - B->sign;

}

int main() {
	int n;
	scanf("%d", &n);
	Node in[n];
	for (int i = 0; i < n; i++) {
		char s[200];
		scanf("%s", s);
		int len = strlen(s);
		if (s[0] == '+') {
			in[i].sign = 1;
			in[i].c = 1;
			int t = 1;
			while (s[t] != '.' && t < len)
				t++;
			int j = 0;
			for (; j < t - 1; j++)
				in[i].it[j] = s[j + 1];
			in[i].it[++j] = '\0';
			int o = 0;
			for (int k = t + 1; k < len; k++)
				in[i].db[o++] = s[k];
			in[i].db[o] = '\0';
		} else if (s[0] == '-') {
			in[i].sign = -1;
			int t = 1;
			while (s[t] != '.' && t < len)
				t++;
			int j = 0;
			for (; j < t - 1; j++)
				in[i].it[j] = s[j + 1];
			in[i].it[++j] = '\0';
			int o = 0;
			for (int k = t + 1; k < len; k++)
				in[i].db[o++] = s[k];
			in[i].db[o] = '\0';
		} else {
			in[i].sign = 1;
			int t = 0;
			while (s[t] != '.' && t < len)
				t++;
			int j = 0;
			for (; j < t; j++)
				in[i].it[j] = s[j];
			in[i].it[j] = '\0';
			int o = 0;
			for (int k = t + 1; k < len; k++)
				in[i].db[o++] = s[k];
			in[i].db[o] = '\0';
		}
	}
	qsort(in, n, sizeof(in[0]), cmp);
	for (int i = 0; i < n; i++) {
		if (in[i].c == 1)
			printf("+");
		if (in[i].sign == -1)
			printf("-");
		if (strlen(in[i].db) != 0)
			printf("%s.%s\n", in[i].it, in[i].db);
		else
			printf("%s\n", in[i].it);
	}

	return 0;
}
