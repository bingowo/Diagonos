#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

unsigned char tmp[17], w[16] = {'\0'};
int n;

void arrange_all(void);
void clear_arr(void);
int isinw(char);
int sortw(const void *, const void *);
void print_all(void);

int main(void)
{
	int num, idx = 0;
	scanf("%d", &num);
	while (num--) {
		printf("case #%d:\n", idx++);
		n = 0;
		scanf("%s", tmp);
		arrange_all();
		print_all();
	}
}

void print_all(void)
{
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j <= n; ++j) {
			int t = i;
			while (t != j)
				putchar(w[t++]);
			putchar('\n');
		}
}

void arrange_all(void)
{
	clear_arr();
	for (int i = 0; tmp[i] != '\0'; ++i)
		if (isinw(tmp[i]) == 0)
			w[n++] = tmp[i];
	qsort(w, n, sizeof w[0], sortw);
}

int sortw(const void *a, const void *b)
{
	return *(unsigned char *)a - *(unsigned char *)b;
}

int isinw(char ch)
{
	for (int i = 0; i < 16; ++i)
		if (w[i] == ch)
			return 1;
	return 0;
}

void clear_arr(void)
{
	for (int i = 0; i < 16; ++i)
		w[i] = '\0';
}