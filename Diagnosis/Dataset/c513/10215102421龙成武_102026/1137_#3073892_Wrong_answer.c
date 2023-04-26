#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void BigIntSum(char* a, char* b, char* c)
{
	int i,j,la, lb,maxlen,ai[200], bi[200], ci[200];
	la = strlen(a);
	lb = strlen(b);
	memset(ai, 0, sizeof(ai));
	memset(bi, 0, sizeof(bi));
	memset(ci, 0, sizeof(ci));
	for (i = la - 1;i > -1;i--)
	{
		ai[la - 1 - i] = a[i] - '0';
	}
	for (j = lb - 1;j > -1;j--)
	{
		bi[lb - 1 - j] = b[j] - '0';
	}
	if (la > lb)	maxlen = la + 1;
	else	maxlen = lb + 1;
	for (i = 0;i < maxlen;i++)
	{
		ci[i] = ai[i] + bi[i];
	}
	for (i = 0;i < maxlen;i++)
	{
		if (ci[i] > 9)
		{
			ci[i + 1] += 1;
			ci[i] -= 10;
		}
	}
	for (i = maxlen-1;i > -1;i--)
	{
		if (ci[i] != 0)
		{
			maxlen = i+1;
			break;
		}
	}
	for (i = maxlen - 1;i > -1;i--)
	{
		c[maxlen - 1 - i] = ci[i] + '0';
	}
	c[maxlen] = 0;
}
int main()
{
	char a[200], b[200],c[200];
	int i,j,temp, la, lb;
	scanf("%s %s", a, b);
	BigIntSum(a, b, c);
	puts(c);
}