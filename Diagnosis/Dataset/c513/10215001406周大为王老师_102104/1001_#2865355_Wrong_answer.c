#include<stdio.h>
#include<math.h>
void rever(int num, int tmp)
{
	int num2 = num;
	char pri = 'A';
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
			printf("%d", num);
		}
		else if (num2 > 9)
		{
			tmp = tmp - 11;
			printf("%c", pri + tmp);
		}
	}
	printf("\n");
}
int main()
{
	int t;
	int a[2];
	int tmp = 0;
	int num = 0;
	scanf("%d\n", &t);
	for (;t >= 0; t--)
	{
		for (int i = 0;i < 2; i++)
		{
			scanf("%d", &a[i]);//23 12 
		}
		num = a[0];
		tmp = a[1];
		rever(num, tmp);
	}

	return 0;
}