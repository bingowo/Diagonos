#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int a = 0, b = 0;
	char ch[3000] = { 0 };
	scanf("%d%d", &a,&b);
	int i = 0, k = 1, n = 0;
	int tmp = 0;
	tmp = a%b;
	a = (a - tmp) / b;
	for (;;n++,k *= 3)
	{
		if (b%k != 0)
		{
			k /= 3;
			n--;
			break;
		}
	}
	if (a == 0)
	{
		ch[i] = '0';
	}
	while (a != 0)
	{
		if (a % 3 == 1)
		{
			ch[i] = '1';
			a /= 3;
		}
		else if (a % 3 == 2)
		{
			ch[i] = '2';
			a /= 3;
			a++;
		}
		else
		{
			ch[i] = '0';
			a /= 3;
		}
		i++;
	}
	int record = i;
	for (int j = strlen(ch) - 1;j >= 0;j--)
	{
		printf("%c", ch[j]);
	}
	if (tmp != 0)
	{
		for (int m = 0;m < n;m++)
		{
			ch[i + m] = '0';
		}
		printf(".");
		while (tmp != 0)
		{
			if (tmp % 3 == 1)
			{
				ch[i] = '1';
				tmp /= 3;
			}
			else if (tmp % 3 == 2)
			{
				ch[i] = '2';
				tmp /= 3;
				tmp++;
			}
			else
			{
				ch[i] = '0';
				tmp /= 3;
			}
			i++;
		}
		for (int j = strlen(ch) - 1;j >= record;j--)
		{
			printf("%c", ch[j]);
		}
	}
	return 0;
}