#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 102
void plus(int b[N+1],int* len)
{
	int c[N + 1] = { 0 };
	int a[N + 1] = { 0 };
	for (int i = 1; i < *len; i++)
		a[*len - i] = b[i];
	int lc = len + 1;

	for (int i = 1; i < lc; i++)
	{
		if (i == 1)
		{
			c[i] += a[i] + 1;
			c[i + 1] = c[i] / 10;
			c[i] = c[i] % 10;
		}
		else
		{
			c[i] += a[i] + 0;
			c[i + 1] = c[i] / 10;
			c[i] = c[i] % 10;
		}
	}
	if (c[lc] == 0 && lc > 0)lc--;
	int j=1;
	for (int i = lc, j = 1; i > 0; i--, j++)
		b[j] = c[i];
	*len = j;
}
void del(int* L, int* x, int* len)
{
	int c[N + 1];
	int b[N + 1];
	if (L[0] == 1)
	{
		for (int i = 1; i < *len; i++)
		{
			c[i] = (*x * 10 + L[i]) / 2;
			*x = (*x * 10 + L[i]) % 2;
		}
		b[0] = -1;
		int lc= 1;
		int k = 1;
		while (c[lc] == 0 && lc < *len) lc++;
		for (k = 1; lc < *len; lc++, k++);
		{
			b[k] = c[lc];
		
		}
		*len = k;
		*L = b;
	}
	else if (L[0] == -1)
	{
		b[0] = 1;
		for (int i = 1; i < len; i++)
		{
			c[i] = (*x * 10 + L[i]) / 2;
			*x = (*x * 10 + L[i]) % 2;
		}
		int lc = 1;
		int k = 1;
		while (c[lc] == 0 && lc < len) lc++;
		for (k = 1; lc < len; lc++, k++);
		{
			b[k] = c[lc];

		}
		plus(&b,&k);
		*len = k;
		*L = b;
	}
}
int main()
{
	char s[N + 1];
	fgets(s, N + 1, stdin);
	int L[N + 1];
	int i = 0;
	int len;
	if (s[strlen(s) - 1] == '\n')
		s[strlen(s) - 1] = 0;
	if (s[0] == '-')
	{
		L[0] = -1;
		for (i = 1; i < strlen(s); i++)
			L[i] = s[i] - '0';
		len = i;
	}
	else
	{
		L[0] = 1;
		for (i = 0; i < strlen(s); i++)
			L[i + 1] = s[i] - '0';
		len = i + 1;
	}
	int x = 0;

	int yu[N + 1];
	i = 0;
	while (!(len==2&&L[1]==0))
	{
		del(&L, &x, &len);
		yu[i] = x;
		i++;
	}
	for (int k = i-1; k>=0; k++)
		printf("%d", yu);
}