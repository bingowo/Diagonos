# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char stack[105] = { 1 };

void remov(char* str)
{
	for (int i = 0; i < 105; ++i)   stack[i] = 0;
	int len = strlen(str);
	int e = 0;
	for (int i = 0; i < len; i++)
	{
		if (i == 0)
		{
			if (str[i] == str[i + 1]);
			else stack[e++] = str[i];
		}
		else if (i == len - 1)
		{
			if (str[i] == str[i - 1]);
			else stack[e++] = str[i];
		}
		else
		{
			if (str[i] == str[i + 1] || str[i] == str[i - 1]);
			else stack[e++] = str[i];
		}
	}
	int llen = strlen(stack);
	if (len == llen)
	{
		stack[0] = 0;
		return;
	}
	else 
	{
		int i = 0;
		for (i = 0; i < llen; ++i)  str[i] = stack[i];
		str[i] = 0;
		stack[0] = 1;
	}
	return;
}
int main()
{
	int cases;
	scanf("%d", &cases);
	for (int cas = 0; cas < cases; ++cas)
	{
		//ps = 0;
		stack[0] = 1;
		char str[105] = { 0 };
		scanf("%s", str);
		int len = strlen(str);
		int m = 0;
		while (stack[0] != 0)
		{
			remov(str);
			printf("%s   %d   %d\n", str, len - strlen(str),m++);
		}
		
		int llen = strlen(str);
		if (llen == 0)  len += 1;
		else if (llen == 1)  len += 2;
		else
		{
			int maxj = 0;
			for (int i = 0; i < llen; ++i)
			{
				int j = 1;
				while (str[i - j] && str[i + j] && str[i - j] == str[i + j])
				{
					++j;
				}
				maxj = maxj > j ? maxj : j;
			}
			len += 2 * maxj;
		}
		printf("case #%d:\n", cas);
		printf("%d\n", len - strlen(str));
	}
	return 0;
}