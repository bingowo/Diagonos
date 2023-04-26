#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int t;
	char ch[121] = { 0 };
	int len;
	char tmp;
	scanf("%d", &t);
	for (; t >= 0; t--)
	{
	    int gcd = 1;
		gets(ch);
		int count = 0;
		len = strlen(ch);
		for (int i = 0; i < len; i++)
		{
			int a = 1;
			tmp=ch[i];
			while(tmp)
			{
			    if(a&tmp)
			    {
			        count++;
			    }
			    tmp<<1;
			}
		}
		len *= 8;
		for (int j = 2; j < len; j++)
		{
			if ((count % j == 0) && (len % j == 0))
			{
				gcd = j;continue;
			}
			if (j + 1 == len)
			{
				count /= gcd;
				len /= gcd;
				printf("%d/%d\n", count, len);
			}
		}

	}
	return 0;
}