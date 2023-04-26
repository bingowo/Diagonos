#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float a[128];

int cmp(const void *a, const void *b);

int main()
{
	int T,t;
	scanf("%d", &T);
	t = T;
	while(T)
	{
		for (int i = 0; i < 26; i++)
		{
			scanf ("%f", &a['A'+i]);
			a['a'+i] = a['A'+i];
		}
		char b[110];
		scanf ("%s", b);
		qsort(b, strlen(b), sizeof(b[0]), cmp);
		printf("case #%d:\n%s\n", t-T, b);
		T--;
	}
	return 0;
}

int cmp(const void *m, const void *n)
{
	char *p1 = (char *)m, *p2 = (char *)n;
	if (a[*p1] != a[*p2]) return a[*p2] - a[*p1];
	else return *p2 - *p1;
} 