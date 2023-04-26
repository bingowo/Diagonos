#include<stdio.h>
int main(int argv, char* argc[])
{
	char ch = 0;
	int opt;
	while((ch = getchar()) != EOF)
	{
//		cerr << "in   " << ch << " " << opt << endl;
		if(opt == 0)
		{
			if((ch == '/'))
			{
				opt = 1;
			}
			else if(ch == '\"')
			{
				putchar(ch);
				opt = 5;
			}
			else if(ch == '\\')
			{
				putchar(ch);
				opt = 6;
			}
			else
			{
				putchar(ch);
			}
		}
		else if(opt == 1)
		{
			if(ch == '/')
			{
				opt = 4;
			}
			else if(ch == '*')
			{
				opt = 2;
			}
			else
			{
				putchar('/');
				putchar(ch);
				opt = 0;
			}
		}
		else if(opt == 2)
		{
			if(ch == '*')
			{
				opt = 3;
			}
		}
		else if(opt == 3)
		{
			if(ch == '/')
			{
				opt = 0;
			}
			else if(ch != '*')
			{
				opt = 2;
			}
		}
		else if(opt == 4)
		{
			if(ch == '\n')
			{
				putchar('\n');
				opt = 0;
			}
		}
		else if(opt == 5)
		{
			putchar(ch);
			if(ch == '\"')
				opt = 0;
			if(ch == '\\')
				opt = 7;
		}
		else if(opt == 6)
		{
			putchar(ch);
			opt = 0;
		}
		else if(opt == 7)
		{
			putchar(ch);
			opt = 5;
		}
//		cerr << "out  " << ch << " " << opt << endl;
	}
	return 0;
}