# include <stdio.h>
# include <stdlib.h>
# include <string.h>
int ps = 0;
char stack[105] = {0};
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
	return stack[ps-1];
}
int empty(void)
{
	if (stack[0] == 0)   return 1;
	return -1;
}
int main()
{
	int cases;
	scanf("%d", &cases);
	for (int cas = 0; cas < cases; ++cas)
	{
		ps = 0;
		char str[105] = { 0 };
		scanf("%s", str);
		for (int i = 0; i < 105; ++i)   stack[i] = 0;
		int len = strlen(str);
		for (int i = 0; i < len; i++)
		{
			if (empty()==1)   push(str[i]);
			else if (str[i] != top())   push(str[i]);
			else
			{
				if (str[i] == str[i + 1]);
				else pop();
			}
			//printf("%s\n", stack);
		}
		int llen = strlen(stack);
		if (llen == 0)  len += 1;
		else if (llen == 1)  len += 2;
		else
		{
			int maxj = 0;
			for (int i = 0; i < llen; ++i)
			{
				int j = 1;
				while (stack[i-j]&&stack[i+j]&& stack[i - j]== stack[i + j])
				{
					++j;
				}
				maxj = maxj > j ? maxj : j;
			}
			len += 2 * maxj;
		}
		printf("case #%d:\n", cas);
		printf("%d\n",len - strlen(stack));
	}
	return 0;
}