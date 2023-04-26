#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct team
{
	int name;
	int score;
	int yes;
	int no;
};
int cmp(const void *e1, const void* e2)
{
	struct team p1 = *(struct team*)e1;
	struct team p2 = *(struct team*)e2;
	if (p1.score != p2.score)
		return p2.score - p1.score;
	else
	{
		if (p1.yes != p2.yes)
			return p2.yes - p1.yes;
		else
		{
			if (p1.no != p2.no)
				return p1.no - p2.no;
			else return p2.name - p1.name;
		}
	}
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	while (n != 0 || m != 0)
	{
		int i = 0; int a, b, c;
		struct team* s = (struct team*)malloc(sizeof(struct team)*m*2);
		for (i = 0; i < m*2-1; i+=2)
		{
			scanf("%d%d%d", &a, &b, &c);
			if (c == 1)
			{
				s[i].name = a;
				s[i].score = 3;
				s[i].yes = 1;
				s[i].no = 0;
				s[i + 1].name = b;
				s[i + 1].score = -1;
				s[i+1].yes = 0;
				s[i+1].no = 1;
			}
			else if (c == -1)
			{
				s[i].name = b;
				s[i].score = 3;
				s[i].yes = 1;
				s[i].no = 0;
				s[i + 1].name = a;
				s[i + 1].score = -1;
				s[i + 1].yes = 0;
				s[i + 1].no = 1;
			}
			else if (c == 0)
			{
				s[i].name = b;
				s[i].score = 1;
				s[i].yes = 0;
				s[i].no = 0;
				s[i + 1].name = a;
				s[i + 1].score = 1;
				s[i + 1].yes = 0;
				s[i + 1].no = 0;
			}
		}
		struct team* t = (struct team*)malloc(sizeof(struct team)*n);
		for (i = 0; i < n; i++)
		{
			int score = 0; int yes = 0, no = 0;
			for (int j = 0; j < 2 * m; j++)
			{
				if (s[j].name == i+1)
				{
					yes = yes + s[j].yes;
					score = score + s[j].score;
					no = no + s[j].no;
				}
			}
			t[i].name = i + 1;
			t[i].score = score;
			t[i].yes = yes;
			t[i].yes = yes;
		}
		free(s);
		qsort(t, n, sizeof(t[0]), cmp);
		for (i = 0; i < n - 1; i++)
			printf("%d ", t[i].name);
		printf("%d\n", t[i].name);
		free(t);
		scanf("%d%d", &n, &m);

	}
	return 0;
}