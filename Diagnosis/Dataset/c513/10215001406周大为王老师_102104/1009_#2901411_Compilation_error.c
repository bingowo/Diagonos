提交 #2895611
#	送交者	题目	语言	提交时间	评测时间	结果	耗时	内存	评测机
2895611	10215001406	1009. 数据密度	C	2022-03-03 21:44:08	2022-03-03 21:44:09	
Wrong answer: 0
0.006	0.336	Amiya
 C
 Copy
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int t;
	char ch[121] = { 0 };
	int count = 0;
	int gcd = 0;
	int len;
	int tmp;
	scanf("%d", &t);
	for (; t > 0; t--)
	{
		gets(ch);
		len = strlen(ch);
		for (int i = 0; i < len; i++)
		{
			tmp = (int) ch[i];
			for (;tmp > 0 ;)
			{
				int rest;
				rest = ((int)(tmp / 2));
				rest = tmp - rest * 2;
				if (rest == 1)
				{
					count++;
				}
				tmp /= 2;
			}
		}
		len *= 8;
		for (int j = 2; j < len; j++)
		{
			if ((count % j == 0) && (len % j == 0))
			{
				gcd = j;continue;
			}
			count /= gcd;
			len /= gcd;
		}
		printf("%d/%d\n", count , len );
	}
	return 0;
}