#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int t = 0 ;
	char arr[100] = { 0 };
	scanf("%d", &t);
	for (int k = 0; k < 100; k++)
	{
		arr[k] = 0;
	}
	for (int i = 0;i < t;i++)
	{
		scanf("%s", &arr);
		char* p = arr;
		long sum = 0;
		int j = 0;
		for (;j < strlen(arr); j++)
		{
			sum = sum * 3;
			if (arr[j] == '1')
			{
				sum += 1;
			}
			else if (arr[j] == '0')
			{
				;
			}
			else if (arr[j] == '-')
			{
				sum -= 1;
			}		}
		printf("case #%d:\n",i);
		printf("%ld\n", sum);
	}
	return 0;
}