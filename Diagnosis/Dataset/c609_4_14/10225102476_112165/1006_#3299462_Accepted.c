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
		scanf("%s", arr,61);
		int turn[128] = { 0 };
		int i = 0, fundem = 0;
		char* p = arr;
		int count = 1;
		long long ret = 0;
		for (int j = 0; j < 128; j++)
		{
			turn[j] = -1;
		}
		turn[*p] = 1;
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
		printf("case #%d:\n", h);
		printf("%lld\n", ret);
		h++;
	}
	return 0;
}