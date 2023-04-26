#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char s[200];
int p = 0;
void push(char c)
{
	s[p++] = c;
}
void out()
{
	p--;
}
int judge(char b)
{
	if (p == 0 && b != ']' && b != '}' && b != ')')
	{
		push(b);
		return 1;
	}
	switch (b)
	{
	case '{':
	{
		if (s[p-1] == '(')
		{
			push('{');
			return 1;
		}
		else return 0;
	}
	case'}':
	{
		if (s[p-1] == '{')
		{
			out();
			return 1;
		}
		else return 0;
	}
	case '(':
	{
		if (s[p-1] == '[')
		{
			push('(');
			return 1;
		}
		else return 0;
	}
	case')':
	{
		if (s[p-1] == '(')
		{
			out();
			return 1;
		}
		else return 0;
	}
	case '[':
	{
		if (s[p-1] == '{')
		{
			push('[');
			return 1;
		}
		else return 0;
	}
	case']':
	{
		if (s[p-1] == '[')
		{
			out();
			return 1;
		}
		else return 0;
	}

	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int flag = 1;
	char s1[200];
	for (int g = 0;g < n;g++)
	{
		scanf("%s", s1);
		for (int i = 0;i < strlen(s1);i++)
		{
			if (judge(s1[i]));
			else
			{
				flag = 0;
				break;
			}
		}
		if (p != 0)flag = 0;
	if (flag)
		{
			printf("Yes\n");
		}
		else printf("No\n");
	
	
	}	

	return 0;
   
}
