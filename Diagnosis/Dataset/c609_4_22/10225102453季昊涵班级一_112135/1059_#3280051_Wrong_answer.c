#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	double a;
	char s[105];
} Node;

int cmp(const void *a, const void *b) {
	Node *A = (Node *)a;
	Node *B = (Node *)b;
	if (A->a > B->a)
		return 1;
	else
		return -1;

}

int main() {
	int n;
	scanf("%d", &n);
	Node in[n];
	for (int i = 0; i < n; i++) {
		scanf("%s", &in[i].s);
		if (in[i].s[0] == '+') {
			int len = strlen(in[i].s);
			char temp[105];
			int j = 0;
			for (int i = 1; i < len; i++)
				temp[j++] = in[i].s[i];
			temp[j] = '\0';
			in[i].a = atof(temp);
		} else
			in[i].a = atof(in[i].s);
	}
	qsort(in, n, sizeof(in[0]), cmp);
	for (int i = 0; i < n; i++)
		printf("%s\n", in[i].s);


	return 0;
}
