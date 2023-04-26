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
	char lp[N + 1];
	int i = 0;
	for (i = 0; (s[i] != s[i + 1]) && (i < strlen(s) - 1); i++);
	if (i == strlen(s) - 1) return s;
	else if (strlen(s) < 1) return s;
	struct d M[N]; int j = 0;
	for (i = 0, j = 0; i < strlen(s) - 1;)
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
			lp[h] = s[i];
			h++;
		}
		i = i + M[k].cout;
	}
	for (; i < strlen(s); i++, h++)
		lp[h] = s[i];
	lp[h] = '\0';
	return solve(lp);

}
int Max(int* L,int j)
{
	int max = L[0];
	for (int i = 1; i <j; i++)
	{
		if (L[i]>max)
			max = L[i];
	}
	return max;
}
int main()
{
	int T=1;
	scanf("%d",&T);
	char s[N+1];
	char* p;
	char D[N + 1];
	int len[N + 1];
	for (int i = 0; i < T; i++)
	{
		scanf("%s\n",s);
		p = solve(s); int f;
		for (f = 0; f < strlen(p); f++)
			D[f] = p[f];
		D[f] = '\0';
		int lenth = strlen(s) - strlen(D); int LEN;
		if (strlen(D) <= 1)
			LEN = lenth + 1+ strlen(D);
		else
		{
			int j;
			for (j = 0; j < strlen(D); j++)
			{
				char a[N + 1];
				int k;
				for (k = 0; k <= j; k++)
					a[k] = D[k];
				a[j + 1] = D[j];
				for (k = j + 2; k < strlen(D) + 1; k++)
					a[k] = D[k - 1];
				a[k] = '\0';
				char * x = solve(a);
				len[j] = strlen(a) - strlen(x);

			}
			int max = Max(len,j);
			LEN = lenth + max;
			if(strlen(D)%3==0&&strlen(D)/3>1)
			LEN++;
		}
		printf("case #%d:\n", i);
		printf("%d\n", LEN);
	}
	return 0;
}