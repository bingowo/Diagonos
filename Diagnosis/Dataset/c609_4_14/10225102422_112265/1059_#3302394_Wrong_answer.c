#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
struct m
{
	int s1[N + 1];
	int len1;
	int s2[N + 1];
	int len2;
	char s[N + 1];
};
int cmp(const void* e1, const void* e2)
{
	struct m p1 = *(struct m*)e1;
	struct m p2 = *(struct m*)e2;
	if (p1.len1 != p2.len1)
	{
		if (p1.s1[0] != p2.s1[0])
			return p1.s1[0] - p2.s1[0];
		else
		{
			if (p1.s1[0] == -1)
			{
				return p2.len1 - p1.len1;
			}
			else
				return p1.len1 - p2.len1;
		}
	}
	else
	{
		int i;
		if (p1.s1[0] == -1 && p2.s1[0] == -1)
		{
			for (i = 0;i < p1.len1;i++)
			{
				if (p1.s1[i] != p2.s1[i])
					return p2.s1[i] - p1.s1[i];
			}
			if (i == p1.len1)
			{
				int len2 = p1.len2 > p2.len2 ? p2.len2 : p1.len2;
				for (int i = 0;i < len2;i++)
				{
					if (p1.s2[i] != p2.s2[i])
						return p2.s2[i] - p1.s2[i];
				}
				if (i == len2)
				{
					return p2.len2 - p1.len2;
				}
			}
		}
		else
		{
			for (i = 0;i < p1.len1;i++)
			{
				if (p1.s1[i] != p2.s1[i])
					return p1.s1[i] - p2.s1[i];
			}
			int len2 = p1.len2 > p2.len2 ? p2.len2 : p1.len2;
				if (len2 == 0)
				{
					if (p1.len2 == 0)
						return p1.len2 - p2.len2;
					else
						return p2.len2 - p1.len2;
				}
				else
				{
					for (int i = 0;i < len2;i++)
					{
						if (p1.s2[i] != p2.s2[i])
							return p1.s2[i] - p2.s2[i];
					}
					if (i == len2)
					{
						return p1.len2 - p2.len2;
					}
				}
		}
	}
}
int main()
{
	int T;
	scanf("%d\n", &T);
	struct m* M = (struct m*)malloc(sizeof(struct m)*T);
	for (int i = 0;i < T;i++)
	{
		fgets(M[i].s, N + 1, stdin);
		if (M[i].s[strlen(M[i].s) - 1] == '\n')
			M[i].s[strlen(M[i].s) - 1] = 0;
		int j;
		for (j = 0;M[i].s[j] != '.'&&j<strlen(M[i].s);j++);
		if (j == strlen(M[i].s) - 1)
		{
			int k;
			M[i].len2 = 0;
			if (M[i].s[0] == '-')
			{
				M[i].s1[0] = -1;
				for (k = 1;k < strlen(M[i].s);k++)
				{
					M[i].s1[k] = M[i].s[k] - '0';
				}
				M[i].len1 = k;
			}
			else if (M[i].s[0] == '+')
			{
				M[i].s1[0] = 1;
				for (k = 1;k < strlen(M[i].s);k++)
				{
					M[i].s1[k] = M[i].s[k] - '0';
				}
				M[i].len1 = k;
			}
			else if (M[i].s[0] >= '0'&&M[i].s[0] <= '9')
			{
				M[i].s1[0] = 1;
				for (k = 0;k < strlen(M[i].s);k++)
				{
					M[i].s1[k + 1] = M[i].s[k] - '0';
				}
				M[i].len1 = k + 1;
			}
		}
		else
		{
			int k;
			if (M[i].s[0] == '-')
			{
				M[i].s1[0] = -1;
				for (k = 1;k < j;k++)
				{
					M[i].s1[k] = M[i].s[k] - '0';
				}
				M[i].len1 = k;
			}
			else if (M[i].s[0] == '+')
			{
				M[i].s1[0] = 1;
				for (k = 1;k < j;k++)
				{
					M[i].s1[k] = M[i].s[k] - '0';
				}
				M[i].len1 = k;
			}
			else if (M[i].s[0] >= '0'&&M[i].s[0] <= '9')
			{
				M[i].s1[0] = 1;
				for (k = 0;k <j;k++)
				{
					M[i].s1[k + 1] = M[i].s[k] - '0';
				}
				M[i].len1 = k + 1;
			}
			int u = 0;
			for (k = j + 1;k < strlen(M[i].s);k++, u++)
				M[i].s2[u] = M[i].s[k] - '0';
			M[i].len2 = u;
		}
	}
	qsort(M, T, sizeof(M[0]), cmp);
	for (int i = 0;i < T;i++)
		printf("%s\n", M[i].s);
	return 0;
}
