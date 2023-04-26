#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int empty(char* s1)//判断栈是否为空
{
	if (strlen(s1) == 0) return 1;
	else return 0;
}
void insert(char* s1, char c)//插入元素
{
	int len = strlen(s1);
	s1[len++] = c;
	s1[len] = '\0';
}
void pop(char* s1)//弹出栈顶元素
{
	s1[strlen(s1) - 1] = '\0';
}
char top(char* s1)//获得栈顶元素
{
	return s1[strlen(s1) - 1];
}
int main()
{
	int t;
	scanf("%d", &t);
	char* stack, s[101];
	for (int k = 0; k < t; k++)
	{
		scanf("%s", s);
		stack = (char*)malloc(101, sizeof(char));
		int len = strlen(s);
		for (int i = 0; i < len; i++)
		{
			if (empty(stack))
			{
				insert(stack, s[i]);continue;
			}
			if (s[i] == '(')
			{
				if (top(stack) != '[')
					break;
				else
					insert(stack, s[i]);
			}
			if (s[i] == '[')
			{
				if (top(stack) != '{')
					break;
				else
					insert(stack, s[i]);
			}
			if (s[i] == '{')
			{
				if (top(stack) != '(')
					break;
				else
					insert(stack, s[i]);
			}
			if (s[i] == ')')
			{
				if (top(stack) != '(')
					break;
				else
					pop(stack);
			}
			if (s[i] == ']')
			{
				if (top(stack) != '[')
					break;
				else
					pop(stack);
			}
			if (s[i] == '}')
			{
				if (top(stack) != '{')
					break;
				else
					pop(stack);
			}
		}
		if (empty(stack)) printf("Yes\n");
		else printf("No\n");
		free(stack);
	}
	return 0;
}