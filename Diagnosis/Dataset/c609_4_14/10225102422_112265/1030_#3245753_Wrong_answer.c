#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define N 100
struct ch
{
	double HZ;
	char c;
};
int cmp(const void* e1, const void* e2)
{
	struct ch p1 = *(struct ch*)e1;
	struct ch p2 = *(struct ch*)e2;
	if (p1.HZ != p2.HZ)
	{
		if (p1.HZ > p2.HZ)
			return -1;
		else
			return 1;
	}
	else
	{
		if (abs(p1.c - p2.c) != 32)
		{
			if ((p1.c >= 'A'&&p1.c <= 'Z'&&p2.c >= 'A'&&p2.c <= 'Z') || (p1.c >= 'a'&&p1.c <= 'z'&&p2.c >= 'a'&&p2.c <= 'z'))
				return p1.c - p2.c;
			else if (p1.c >= 'A'&&p1.c <= 'Z'&&p2.c >= 'a'&&p2.c <= 'z')
				return p1.c + 32 - p2.c;
			else if (p1.c >= 'a'&&p1.c <= 'z'&&p2.c >= 'A'&&p2.c <= 'Z')
				return p1.c - 32 - p2.c;
		}
		else
		{
			return p2.c - p1.c;
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		double L[26];
		double m;
		for (int j = 0; j < 26; j++)
		{
			scanf("%lf", &m);
			L[j] = m;
		}
		char c; struct ch s[N]; int j = 0;
		while ((c = getchar()) != '\n')
		{
			s[j].c = c;
			if (c >= 'A'&&c <= 'Z')
				s[j].HZ = L[c - 'A'];
			else if (c >= 'a'&&c <= 'z')
				s[j].HZ = L[c - 'a'];
			j++;
		}
		int len = j;
		qsort(s, len, sizeof(s[0]), cmp);
		printf("case #%d:\n", i);
		for (j = 0; j < len; j++)
			printf("%c", s[j].c);
		printf("\n");
	}
	return 0;
}