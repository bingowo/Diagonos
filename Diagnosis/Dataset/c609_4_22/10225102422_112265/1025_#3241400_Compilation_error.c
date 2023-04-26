#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct team
{
	int name;
	int sore;
	int yes;
	int no;
}{0};
int cmp(const void* e1, const void* e2)
{
	struct team p1 = *(struct team*)e1;
	struct team p2 = *(struct team*)e2;
	if (p1.sore != p2.sore)
		return p2.sore - p1.sore;
	else
	{
		if (p1.yes != p2.yes)
			return p2.yes - p1.yes;
		else
		{
			if (p1.no != p2.no)
				return p1.no - p2.no;
			else
				return p1.name - p2.name;
		}
	}

}
int main()
{
	int n;
	int m;
	scanf("%d%d\n", &n, &m);
	while (n!=0||m!=0)
	{
		int i = 0; int c;
		struct team* teams = (struct team*)malloc(sizeof(struct team)*n);
		for (; m>0; m--)
		{
			int a;int b;
			scanf("%d%d%d\n", &a, &b, &c);
			if (c == 1)
			{
				teams[a].sore += 3;
				teams[b].sore -= 1;
				teams[a].yes++;
				teams[b].no++;
			}
			else if (c == 0)
			{
				teams[a].sore += 1;
				teams[b].sore += 1;
			}
			else if (c == -1)
			{
				teams[b].sore += 3;
				teams[a].sore -= 1;
				teams[b].yes++;
				teams[a].no++;
			}
		}
		qsort(teams, n, sizeof(teams[0]), cmp);
		for (i = 0; i < n - 2; i++)
			printf("%d ", teams[i].name);
		printf("%d\n", teams[i].name);
		scanf("%d%d\n", &n, &m);
	}
	
	
}