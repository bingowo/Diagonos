#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	int x, T, num, i, flag,flag1;
	scanf("%d", &T);
	for (x = 0;x < T;x++)
	{
		printf("case #%d:\n", x);
		//flag = 0;                    //初始默认全0
		//也是做题做晕了，flag和flag1的作用其实是一样的
		flag1 = 0;                   //初始默认没有输出，当有了第一个输出的时候，置1，第一个输出不需要+，只要-
		for (i = 8;i > -1;i--)
		{
			scanf("%d", &num);
			if (i > 1)
			{
				if (num == 0);
				else
				{
					if (num == 1 || num == -1)      //系数是1
					{
						if (flag1 && num == 1)
							printf("+x^%d", i);
						else if (num == 1)
							printf("x^%d", i);
						else if (num == -1)
							printf("-x^%d", i);
					}
					else
					{
						if (flag1)
							printf("%+dx^%d", num, i);
						else
							printf("%dx^%d", num, i);
					}
					flag1 = 1;
				}
			}
			else if (i == 1)
			{
				if (num == 0);
				else
				{
					if (num == 1 || num == -1)      //系数是1
					{
						if (flag1 && num == 1)
							printf("+x");
						else if (num == 1)
							printf("x" );
						else if (num == -1)
							printf("-x" );
					}
					else
					{
						if (flag1)
							printf("%+dx", num);
						else
							printf("%dx", num);
					}
					flag1 = 1;
				}
			}
			else if(i==0)                             //幂次为0
			{
				if (num == 0);
				else
				{
					if (num == 1)
					{
						if (flag1)
							printf("+1");
						else
							printf("1");
					}
					else if (num == -1)
					{
						printf("-1");
					}
					else
					{
						if (flag1)
							printf("%+d", num);
						else
							printf("%d", num);
					}
					flag1 = 1;
				}
				
			}
		}
		if (!flag1)
		{
			printf("0");
		}
		printf("\n");
	}
	return 0;
}