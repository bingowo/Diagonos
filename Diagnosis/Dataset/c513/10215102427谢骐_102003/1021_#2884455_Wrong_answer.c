#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char seq[26 + 1];

int work(void);
void put_ans(char[][20], int);
int acmp(const void *, const void *);

int main(void)
{
	while (1)
		if (work() == EOF)
			return 0;
}

int work(void)
{
	char s[100][20];
	if ((seq[0] = getchar()) == EOF)
		return EOF;
	scanf("%s", &seq[1]);
	getchar();
	int n = 0;
	do {
		scanf("%s", s[n++]);
	} while (getchar() == ' ');
	put_ans(s, n);
	return 0;
}

void put_ans(char s[][20], int n)
{
	qsort(s, n, sizeof(char) * 20U, acmp);
	for (int i = 0; i < n; ++i)
		printf("%s ", s[i]);
	putchar('\n');
}

int acmp(const void *pa, const void *pb)
{
	extern char seq[27];
	char *s1 = (char *)pa, *s2 = (char *)pb;
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
		++s1, ++s2;
	if (*s1 == '\0' || *s2 == '\0')
		return toupper(*s1) - toupper(*s2);
	else
		return seq[toupper(*s1) - 'A'] - seq[toupper(*s2) - 'A'];
}