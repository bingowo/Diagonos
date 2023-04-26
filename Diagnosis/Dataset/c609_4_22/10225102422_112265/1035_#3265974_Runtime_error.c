#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
struct d
{
	int index;
	int cout;
};
char* solve(char* s)
{
	char p[N + 1];
	int i = 0; 
	for (i = 0; (s[i] != s[i + 1]) && i < strlen(s) - 1; i++);
	if (i == strlen(s) - 1) return s;
	struct d M[N]; int j = 0; 
	for (i = 0,j=0; i < strlen(s) - 1;)
	{
		if (s[i] == s[i + 1])
		{
			M[j].index = i;
			int count = 1;
			for (; (i < strlen(s) - 1) && (s[i] == s[i + 1]); i++)
				count++;
			M[j].cout = count;
			j++;
		}
		else
			i++;
	}
	i = 0; int h = 0;
	for (int k = 0; k < j; k++)
	{
		int dex = M[k].index;
		for (; i < dex; i++)
		{
			p[h] = s[i];
			h++;	
		}
		i = i + M[k].cout;
	}
	p[h] = '\0';
	return solve(p);

}
int Max(char* s)
{
	int max = s[0];
	for (int i = 1; i < strlen(s); i++)
	{
		if (s[i]>max)
			max = s[i];
	}
	return max;
}
int main()
{
	int T;
	scanf("%d", &T);
	char s[N + 1];
	char* p;
	int len[N + 1];
	for (int i = 0; i < T; i++)
	{
		scanf("%s", s);
		p = solve(s);

		int lenth = strlen(s) - strlen(p); int LEN;
		if (strlen(p) <= 1)
			LEN = lenth + 1 + strlen(p);
		else
		{
			for (int j = 0; j < strlen(p); j++)
			{
				char* a = (char*)malloc(sizeof(char)*(strlen(s) + 1));
				int k;
				for (k = 0; k <= j; k++)
					a[k] = p[k];
				a[j + 1] = p[k];
				for (k = j + 2; k < strlen(p) + 1; k++)
					a[k] = p[k - 1];
				char * x = solve(a);
				len[j] = strlen(a) - strlen(x);
				free(a);
			}
			int max = Max(len);
			LEN = lenth + max;
		}
		printf("case #%d:\n", i);
		printf("%d\n", LEN);
	}
	return 0;
}