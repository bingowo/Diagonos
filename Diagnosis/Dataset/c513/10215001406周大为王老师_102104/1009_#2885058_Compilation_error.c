#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int reverse(char ch[],int len)
{
	int num = 0;
	int i = 0, j = 0;
	int arr[100] = { 0 };
	int record[800] = { 0 };
	int* p = atoi(ch);
	for (; i < len; i++)
	{
		arr[0] = *(p + 1);
	}
	for (j = 0; j < len+1; j++)
	{
		if (arr[j] > 1)
		{
			record[i] = arr[j] % 2;
			arr[j] /= 2;
			i++;
		}
		else
		{
			record[i] = arr[j];
			break;
		}
	}
	
}
int main()
{
	int t;
	char ch[] = {0};
	int 
	scanf("%d", &t);
	for (; t > 0; t--)
	{
		scanf("%s", ch);
		c = atoi(ch);
		int len = strlen(ch);
		reverse(ch,len);
	}
	return 0;
}