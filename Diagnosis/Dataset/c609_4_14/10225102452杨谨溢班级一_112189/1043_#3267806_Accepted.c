# include <stdio.h>
# include <stdlib.h>
# include <string.h>
// FSM：有限状态自动机：不同状态下 跑来跑去 利用stack储存状态，修改状态
// 否则 多次分类讨论 麻烦！
// 不同情况下 对应不同的状态

# define outer 0  // 外层状态,即空状态，优雅回到的状态
# define paren 1  // 小括号状态
# define brack 2  // 中括号状态
# define brace 3  // 大括号状态
# define filled_brack 4 //  表示【】 中有 （）
# define filled_brace 5 //  表示{}中有【】

int judge(char* str)
{
	int len = strlen(str);
	// 定义一个状态的栈
	int states[500] = { 0 };
	int top = 0;
	for (int i = 0; i < len; ++i)
	{
		int state = states[top];
		char ch = str[i];
		switch (state)
		{
		case outer:
			if (ch == '(')  states[++top] = paren;
			else if (ch == '[') states[++top] = brack;
			else if (ch == '{') states[++top] = brace;
			else return 0;
			break;

		case paren:
			if (ch == '{') states[++top] = brace;
			else if (ch == ')')
			{
				top--;
				if (states[top] != outer)  states[top] = filled_brack;
			}
			else return 0;
			break;

		case brack:
		case filled_brack: // 这两个处理方式相同
			if (ch == '(')  states[++top] = paren;
			else if (ch == ']')
			{
				if (state == brack)  return 0;
				top--;
				if (states[top] != outer) states[top] = filled_brace;
			}
			else return 0;
			break;

		case brace:
		case filled_brace:// 这两个处理方式相同
			if (ch == '[') states[++top] = brack;
			else if (ch == '}')
			{
				if (state == brace) return 0;
				top--;
			}
			else return 0;
			break;
		}
	}
	return states[top] == outer;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char str[105] = { 0 };
		scanf("%s", str);
		printf(judge(str) ? "Yes\n" : "No\n");
	}
	return 0;
}


