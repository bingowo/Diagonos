#include<stdio.h>
#include<stdlib.h>
struct node
{
	int score;
	int id;
	int win;
	int loss;
}a[11];
int cmp(const void *p1, const void *p2)
{
	struct node a, b;
	a = *(struct node*)p1;
	b = *(struct node*)p2;
	if(a.score != b.score)
		return b.score - a.score;
	if(a.win != b.win)
		return b.win - a.win;
	if(a.loss != b.loss)
		return a.loss - b.loss;
	return a.id - b.id;
}
int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m))
	{
		if(!(n|m))
			break;
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; ++i)
			a[i].id = i;
		for(int i = 1; i <= m; ++i)
		{
			int x, y, c;
			scanf("%d %d %d", &x, &y, &c);
			if(c == 1)
			{
				a[x].score += 3;
				--a[y].score;
				++a[x].win;
				++a[y].loss;
			}
			else if(c == -1)
			{
				--a[x].score;
				a[y].score += 3;
				++a[x].loss;
				++a[y].win;
			}
			else
			{
				++a[x].score;
				++a[y].score;
			}
		}
//		for(int i = 1; i <= n; ++i)
//		{
//			printf("cerr %d %d %d %d\n", a[i].id, a[i].score, a[i].win, a[i].loss);
//		}
		qsort(a + 1, n, sizeof(struct node), cmp);
		for(int i = 1; i <= n; ++i)
			printf("%d ", a[i].id);
		puts("");
	}
}