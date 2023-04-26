#include<stdio.h>
#include<math.h>
void rever(int num, int tmp)//230 12
{
	int num2 = 0, i = 0;
	char pri = 'A';
	int arr[10];
	if (num < 0)
	{
		printf("-");
		num = abs(num);
	}
	while (num >= tmp)
	{
		num2 = num % tmp;
		num /= tmp;
		arr[i] = num;
		i++;
	}
	if (num < tmp)
	{
		if (num2 < 10)
		{
			arr[i]=num;
		}
		else if (num2 > 9)
		{
			tmp = tmp - 11;
			pri = pri + tmp;
		}
	}
	for (int j = i-1; j >= 0; j--)
	{
		printf("%d", arr[j]);
	}
	printf("%c\n",pri);
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