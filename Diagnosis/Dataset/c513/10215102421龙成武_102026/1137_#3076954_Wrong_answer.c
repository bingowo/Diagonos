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
void BigIntSub(char *a, char *b, char *c)
{
	int i, j, bit,la, lb, maxlen, ai[200], bi[200], ci[200];
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
	maxlen = la > lb ? la : lb;
	bit = 0;
	for (i = 0;i < maxlen;i++)
	{
		ai[i] -= bit;
		bit = 0;
		if (ai[i] < bi[i])
		{
			bit = 1;
			ci[i] = ai[i] - bi[i] + 10;
		}
		else
		{
			bit = 0;
			ci[i] = ai[i] - bi[i];
		}
	}
	for (i = maxlen - 1;i > -1;i--)
	{
		if (ci[i] != 0)
		{
			maxlen = i + 1;
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
	int signa, signb, signc;
	scanf("%s %s", a, b);
	signa=a[0] == '-' ? -1 : 1;
	signb = b[0] == '-' ? -1 : 1;
	if (signa == 1 && signb == 1)
	{
		BigIntSum(a, b, c);
		signc = 1;
	}
	else if (signa == -1 && signb == -1)
	{
		BigIntSum(a + 1, b + 1, c);
		signc = -1;
	}
	else if (signa == 1 && signb == -1)
	{
		if (strlen(a) > strlen(b)-1)
		{
			BigIntSub(a, b + 1, c);
			signc = 1;
		}
		else if (strlen(a) < strlen(b) - 1)
		{
			BigIntSub(b + 1, a, c);
			signc = -1;
		}
		else if(strcmp(a,b+1)>=0)
		{
			BigIntSub(a, b + 1, c);
			signc = 1;
		}
		else
		{
			BigIntSub(b + 1, a, c);
			signc = -1;
		}
	}
	else if (signa == -1 && signb == 1)
	{
		strcpy(c, a);
		strcpy(a, b);
		strcpy(b, c);
		if (strlen(a) > strlen(b) - 1)
		{
			BigIntSub(a, b + 1, c);
			signc = 1;
		}
		else if (strlen(a) < strlen(b) - 1)
		{
			BigIntSub(b + 1, a, c);
			signc = -1;
		}
		else if (strcmp(a, b + 1) >= 0)
		{
			BigIntSub(a, b + 1, c);
			signc = 1;
		}
		else
		{
			BigIntSub(b + 1, a, c);
			signc = -1;
		}
	}
	if (signc == -1)
		printf("-");
	puts(c);
}