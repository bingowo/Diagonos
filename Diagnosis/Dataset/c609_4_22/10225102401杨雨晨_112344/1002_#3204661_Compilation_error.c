#include<stdio.h>
#include<string.h>
int reverse(int n)
{
	int arr[32] = {0};
	int len;
	for (int i = 0; i < 32; i++)
	{
		if (n > 1)
		{
			arr[i] = n % 2;
			n /= 2;
		}
		else
		{
			arr[i] = n;
			len = i+1;
			break;
		}
	}
	int max = 1, tmp = 1;
	for (int j = 0; j < len ; j++)
	{
		if ((arr[j] != arr[j + 1]) && ((j+1)!=len))
		{
			tmp++;
			if (tmp > max)
			{
				max = tmp;
			}
			continue;
		}
		 if ((j < len) && (arr[j] == arr[j+1]))
		{
			tmp = 1;
			continue;
		}
		if (j == len)
			break;
	}
	return max;
}
int main()
{
	int n,t;
	int max;
	int i = 0;
	scanf("%d", &t);
	for (; t > 0; t--,i++)
	{
		scanf("%d", &n);
		max = reverse(n);
		printf("case #%d:\n", i);
		printf("%d\n", max);
	}

