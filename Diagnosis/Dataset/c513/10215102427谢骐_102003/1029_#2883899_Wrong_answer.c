#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *calc(char *, size_t);
int acmp(const void *, const void *);

int main(void)
{
	int n;
	scanf("%d", &n);
	char s[256];
	for (int i = 0; i < n; ++i) {
		gets(s);
		printf("case #%d:\n", i);
		printf("%s\n", calc(s, strlen(s)));
	}
}

int acmp(const void *pa, const void *pb)
{
	return *(char *)pa - *(char *)pb;
}

char *calc(char *s, size_t len)
{
	char *t = s;
	char alphas[256];
	int n = 0;
	for (int i = 0; i < len; ++i)
		if (s[i] >= 'A' && s[i] <= 'Z')
			alphas[n++] = s[i];
	qsort(alphas, n, sizeof(alphas[0]), acmp);
	n = 0;
	for (int i = 0; i < len; ++i)
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = alphas[n++];
	return t;
}