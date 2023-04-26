#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	int a[2];
	int tmp = 0;
	int num = 0;
	int num2 = 0;
	char pri = 'A';
	scanf("%d\n", &t);
	for (;t >= 0; t--)
	{
		for (int i = 0;i < 2; i++)
		{
			scanf("%d", &a[i]);//23 12 
		}
		num = a[0];//23
		tmp = a[1];//12
		if (num < 0)
		{
			printf("-");
			num = abs(num);
		}
		num2 = num;
		while (num >= tmp)
		{
			printf("1");
			num2 = num2 % tmp;
			num /= tmp;//num = 
		}
		if (num < tmp)
		{
			if (num2 < 10)
			{
				printf("%d\n", num);
			}
			else if (num2 > 9)
			{
				tmp  =tmp - 11;
				printf("%c", pri + tmp);
			}
		}
		printf("\n");		
	}

	return 0;
}