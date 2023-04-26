#include<stdio.h>
#include<string.h>

int main()
{
	char arr[500] = { 0 };
	int a = 0;
	scanf("%s", arr);
	int len = strlen(arr);
	printf("0001");
	char s[11] = { 0 };
	int j = 0;
	for (j = 0; j < 10; j++)
	{
		a = (len >> j) & 1;
		s[9 - j] = a +'0';
	}
	printf("%s", s);
	int i = 0;
	while (len - i >= 3)
	{
		int num = 100 * (arr[i] - '0') + 10 * (arr[i + 1]-'0') + (arr[i + 2]-'0');
		i += 3;
		char ss[11] = { 0 };
		int m = 0;
		for (m = 0; m < 10; m++)
		{
			a = (num >> m) & 1;
			ss[9 - m] = a + '0';
		}
		printf("%s", ss);
	}
	if (len - i == 1)
	{
		int num = arr[i] - '0';
		char one[5] = { 0 };
		int n = 0;
		for (n = 0; n < 4; n++)
		{
			a = (num >> n) & 1;
			one[3 - n] = a + '0';
		}
		printf("%s", one);
	}
	if (len - i == 2)
	{
		int num = (arr[i]-'0') * 10 + arr[i + 1]-'0';
		char two[8] = {0};
		int n = 0;
		for (n = 0; n < 7; n++)
		{
			a = (num >> n)&1;
			two[6- n] = a + '0';
		}
		printf("%s", two);
	}
	return 0;
}