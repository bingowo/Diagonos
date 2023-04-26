#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int main()
{
	int numa, val, lens, i, temp,pos,sign;
	char s[100],a;
	scanf("%s", s);
	lens = strlen(s);
	for (i = 0;i < lens;i++)
	{
		if (!isdigit(s[i]) && s[i] != '+' && s[i] != '-' && s[i] != '=')
		{
			a = s[i];
			break;
		}
	}
	pos = strchr(s, '=') - s;      //pos是=的下标
	val = numa = 0;
	temp = 0;
	sign = 1;
	i = 0;
	if (s[0] == '-') 
	{
		i++;sign = -1;
	}
	while (i <= pos)
	{
		if (isdigit(s[i]))
			temp = temp * 10 + s[i] - '0';
		else if (temp != 0)
		{
			if (s[i] == '+' || s[i] == '-' || i==pos)
			{
				val -= temp * sign;
				if (s[i] == '-') sign = -1;
				else if (s[i] == '+') sign = 1;
			}
			else
			{
				numa += temp * sign;
				sign = 1;
				//a = s[i];
			}
			temp = 0;
		}
		else if (temp == 0)        //等于0但是碰见了符号或者a
		{
			if (s[i] == '+')
			{
				sign = 1;
			}
			else if (s[i] == '-')
			{
				sign = -1;
			}
			else if (s[i] == '=');
			else if (s[i] == a)
			{
				numa += 1 * sign;
			}
		}
		i++;
	}
	i = pos;
	temp = 0;
	sign = 1;
	if (s[i] == '-')
	{
		i++;
		sign = -1;
	}
	while(i<=lens)
	{
		if (isdigit(s[i]))
			temp = temp * 10 + s[i] - '0';
		else if (temp != 0)
		{
			if (s[i] == '+' || s[i] == '-' || i == lens)
			{
				val += temp * sign;
				if (s[i] == '-') sign = -1;
				else if (s[i] == '+') sign = 1;
			}
			else
			{
				numa -= temp * sign;
				sign = 1;
				//a = s[i];
			}
			temp = 0;
		}
		else if (temp == 0)        //等于0但是碰见了符号或者a
		{
			if (s[i] == '+')
			{
				sign = 1;
			}
			else if (s[i] == '-')
			{
				sign = -1;
			}
			else if (s[i] == '=');
			else if (s[i] == a)
			{
				numa -= 1 * sign;
			}
		}
		i++;
	}
	//printf("%d %d", numa, val);
	printf("%c=%.3f", a,val * 1.0 / numa);
	return 0;
}