#include<stdio.h>
int main()
{
	char c;int i=0,cnt=0;
	while((c=getchar())!=EOF)
	{
		switch(i)
		{
			case 0:
				{
					if(c=='"')i=1,putchar(c);
					else if(c=='\\')putchar(c),i=7;
					else if(c=='/')i=2;
					else if(c=='\'')putchar(c),i=8;
					else putchar(c);
					break;
				}
			case 1:
				{
					if(c=='\\')i=6;
					else if(c=='"')i=0;
					putchar(c);
					break;
				}
			case 2:
				{
					if(c=='/')i=3;
					else if(c=='*')i=4;
					else i=1,putchar('/'),putchar(c);
					break;
				}
			case 3:
				{
					if(c=='\n')putchar('\n'),i=0;
					break;
				}
			case 4:
				{
					if(c=='*')i=5;
					break;
				}
			case 5:
				{
					if(c=='/')i=0;
					else if(c!='*')i=4;
					break;
				}
			case 6:
			    {
			        putchar(c),i=1;
			        break;
			    }
			case 7:
			    {
			        putchar(c),i=0;
			        break;
			    }
			case 8:
				{
					if(c=='\'')i=9;
					putchar(c);
					break;
				}
			 case 9:
			    {
			        putchar(c),i=0;
			    }
		}
	}
	return 0;
}
