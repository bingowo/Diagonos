#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int t = 0;
	int h = 0;
	char ch = 0, arr[61];
	scanf("%d", &t);
	for (;t > 0; t--)
	{
		scanf("%s", arr);
		int turn[128] = { 0 };
		int i = 0, fundem = 0;
		char* p = arr;
		int count = 1;//放置在区块内部，使其每一次循环时都进行一次初始化
		long long ret = 0;
		for (int j = 0; j < 128; j++)//较大难点，用ASCII码记录
		{
			turn[j] = -1;
		}
		turn [*p] = 1;//*p即是键盘录入字符串的ASCII，也就是说turn会用下标记录特殊值，
                     // 其余均为-1
		while (*++p)
		{
			if (turn[*p] == -1)
			{
				turn[*p] = fundem;
				if (fundem == 0)
				{
					fundem = 2;
				}
				else
				{
					fundem++;
				}
				count++;
			}
		}
		if (count < 2)
		{
			count = 2;
		}
		p = arr;
		while (*p)
		{
			ret = ret * count + turn[*(p++)];
		}
		printf("case #%d:\n",h );
		printf("%lld\n", ret);
		h++;
	}
	return 0;
}