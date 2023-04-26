#include<stdio.h>
#include<string.h>
int reverse(int x, int y)
{
	int arr[100] = { 0 };
	int str[100] = { 0 };
	int num = 0;
	int i = 0, j = 0;
	for ( j = 0; j < 100; j++)
	{
		if (x > 1)
		{
			arr[j] = x % 2;
			x /= 2;
		}
		else
		{
			arr[j] = x;
			break;
		}
	}
	for ( i = 0; i < 100; i++)
	{
		if (y > 1)
		{
			str[i] = y % 2;
			y /= 2;
		}
		else
		{
			str[i] = y;
			break;
		}
	}
	int max = 0;
	if (j > i)
		max = j;
	else max = i;
	int count = 0;
	for (int k = 0; k < max+1; k++)
	{
		if (arr[k] != str[k])
		{
			count++;
		}
		else
			continue;
	}
	return count;
}
int main()
{
	int t;
	int x, y;
	int num = 0;
	scanf("%d", &t);
	for (; t > 0; t--)
	{
		scanf("%d%d", &x,&y);
		num = reverse(x, y);
		printf("%d\n", num);
	}
	return 0;
}