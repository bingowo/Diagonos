#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trans(char *s) {
	char a[9];
	int j = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			a[j++] = s[i];
	}
	a[j] = '\0';
	if (strlen(a) == 0)
		return -1;
	int out = atoi(a);
	return out;
}

int cmp(const void *a, const void *b) {
	char *A = (char *)a;
	char *B = (char *)b;
	int aa = trans(A);
	int bb = trans(B);
	if (aa == bb)
		return strcmp(A, B);
	else
		return aa - bb;
}

int main() {
	char t[100][31];
	int i = 0;
	while ((scanf("%s", &t[i])) != EOF)
		i++;
	qsort(t, i, sizeof(*t), cmp);
	for (int j = 0; j < i; j++)
		printf("%s ", t[j]);
}