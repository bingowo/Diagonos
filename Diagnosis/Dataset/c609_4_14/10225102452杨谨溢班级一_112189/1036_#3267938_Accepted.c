# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char stack[55] = { 0 };
int ps = 0;
void pop(void)
{
	ps--;
	stack[ps] = 0;
}
void push(char a)
{
	stack[ps] = a;
	ps++;
}
char top(void)
{
	return stack[ps - 1];
}
int empty(void)
{
	if (stack[0] == 0)   return 1;
	return -1;
}

int powint(int n)
{
	// if (n == 1)  return 1;
	int s = 1;
	for (int i = 0; i < n-1; ++i) s = s * 2;
	return s;
}

int main()
{
	char str[55];
	scanf("%s", str);
	int len = strlen(str);
	int cou[55] = { 0 };  // 记录最内层的层数
	int c = 0;
	for (int i = 0; i < len; ++i)
	{
		if (empty() == 1)  push(str[i]);
		else if (str[i] == ')')
		{
			if (str[i - 1] == '(') {
				cou[c++] = ps;
				//printf("PS:%d   ", ps);
			}
			pop();
		}
		else
		{
			push(str[i]);
		}
	}
	c = 0;
	int sum = 0;
	while (cou[c] > 0)
	{
		sum += powint(cou[c]);
		c++;
	}
	printf("%d", sum);
	return 0;
}