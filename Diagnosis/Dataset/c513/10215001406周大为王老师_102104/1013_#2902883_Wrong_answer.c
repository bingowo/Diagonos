#include<stdio.h>
#include<string.h>
#include<math.h>
double and(double a)
{
	return pow(3.0, a);
}
double minus(double b)
{
	return pow(3.0, b);
}
int main()
{
	char ch[100] = { 0 };
	gets(ch);
	double record = 0;
	int len = strlen(ch);
	double tmp = 0;
	int l = 1;
	for (int i = 0; i < len;i++)
	{
		if (ch[i] == '.')
		{
			record = i;break;
		}
	}
	double record1 = record;
	if (record1 == 0)
	{
		int sum = 0;
		int len1 = len;
		for (int j = 0; j < len; len1--,j++)
		{
			if (ch[j] == '1')
			{
				tmp = and (len1 - 1);
				sum += tmp;
			}
			else if (ch[j] == '2')
			{
				tmp = minus(len1 - 1);
				sum -= tmp;
			}
			else;
		}
		printf("%d", sum);
	}
	else
	{
		int sum=0;
		int sum1=0,sum2=0;
		for (int j = 0; j < record1;record--, j++)
		{
			if (ch[j] == '1')
			{
				tmp = and (record - 1);
				sum += tmp;
			}
			else if (ch[j] == '2')
			{
				tmp = minus (record - 1);
				sum -= tmp;
			}
			else;
		}
		for (int k = record1 + 1; k < len;l++,k++)
		{
			double tain = pow(3.0, l);
			if (ch[k] == '1')
			{
				tmp = and (record1-k);
				sum1 = sum1*tain+tmp;
			}
			else if (ch[k] == '2')
			{
				tmp = minus(record1-k);
				sum1 = sum1*tain-tmp;
			}
			else;
		}
		if (sum != 0)
		{
			printf("%d ",sum);
		}
		sum2 = pow(3.0, l);
		printf("%d %d", sum1, sum2);

	}
	return 0;
}