#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int isrepeat(int* a, int len, int n)        //如果循环了，那就返回此前循环点开始的下标
{
	for (int i = 0;i < len;i++)
	{
		if (a[i] == n)
		{
			return i;
		}
	}
	return 0;
}
int main()
{
	int n, m, x, i, T, remain[100], divres[100],digit,pos;
	scanf("%d", &T);
	for (x = 0;x < T;x++)
	{
		printf("case #%d:\n", x);
		scanf("%d %d", &n, &m);
		digit = 0;
		pos = 0;					//pos==0的话说明没有循环节，因为不能从整数0就开始循环
		while (n % m != 0)
		{
			divres[digit] = n / m;
			remain[digit] = n % m;
			n = remain[digit] * 10;
			pos = isrepeat(remain, digit, remain[digit]);
			digit++;
			if (pos != 0)
				break;
		}
		if (!pos)
		{
			divres[digit] = n / m;
			digit++;
		}
		printf("0.");
		for (i = 1;i < digit;i++)
		{
			printf("%d", divres[i]);
		}
		printf("\n");
		if (pos)
		{
			printf("%d-%d\n", pos+1, digit-1);
		}
	}
	return 0;
}