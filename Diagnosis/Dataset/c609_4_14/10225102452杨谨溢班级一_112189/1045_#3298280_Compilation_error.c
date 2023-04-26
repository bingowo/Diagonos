# include <stdio.h>
# include <stdlib.h>
#define ProgWithin cin
#define ProgWithout cout
using namespace std;

int main()
{
	int states = 0;
	char ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\\')
		{
			putchar(ch);
			ch = getchar();
			putchar(ch);
			continue;
		}
		switch (states)
		{
		case 0: // 初始状态
			if (ch == '"') states=2, putchar(ch);
			else if (ch == '\'') states=1, putchar(ch);
			else if (ch == '/') states=3;
			else putchar(ch);
			break;
		case 1: // 单引号
			if (ch == '\'')  states=0;
			putchar(ch);
			break;
		case 2: // 双引号
			if (ch == '"')   states=0;
			putchar(ch);
			break;
		case 3:  // 注释开始 /
			if (ch == '/') states=4;
			else if (ch == '*') states=5;
			else {
				printf("/");
				putchar(ch);
				states=0;
			}
			break;
		case 4:  // 行注释 
			//char c;
			/*do {
				cin.get(c);
			} while (c != '\n');*/
			if (ch == '\n')
			{
				states=0;
				printf("\n");
			}
			break;
		case 5:  // 块注释 /
			if (ch == '*') states=6;
			// else  ProgWithout.put(ch);
			break;
		case 6:  // /**
			if (ch == '/') states=0;
			else if (ch == '*');
			else states=5;
			break;
		}
	}
	return 0;
}