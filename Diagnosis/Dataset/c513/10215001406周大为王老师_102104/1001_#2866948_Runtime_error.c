#include<stdio.h>
#include<math.h>
void rever(long long num, int tmp)//230 12
{
	int num2 = 0, i = 0;
	char pri = 'A';
	int arr[10] = {0};
	if (num < 0)
	{
		printf("-");
		num = abs(num);
	}
	while (num >= tmp)
	{
		num2 = num % tmp;//11
		num /= tmp;//1
		arr[i] = num2;//余数存储中应当将num2转换为超出的字符
		i++;
	}
	if (num < tmp)
	{
			arr[i] = num;
	}
	for (int j = i ; j >= 0; j--)
	{
		if (arr[j] > 9)
		{
			printf("%c", pri + arr[j] - 10);
			continue;
		}
		printf("%lld", arr[j]);
	}
	printf("\n");
}
int main()
{
	int t;
	long long a[2] = {0};
	int tmp = 0;
	long long num = 0;
	scanf("%d\n", &t);
	for (;t > 0; t--)
	{
		for (int i = 0;i < 2; i++)
		{
			scanf("%lld", &a[i]);//23 12 
		}
		num = a[0];
		tmp = a[1];
		rever(num, tmp);
	}

	return 0;
}