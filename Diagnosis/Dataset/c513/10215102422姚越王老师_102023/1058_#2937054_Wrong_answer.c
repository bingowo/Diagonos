#include<stdio.h>
int main()
{
	char c;int i=0,cnt=0;
	while((c=getchar())!=EOF)
	{
		//printf("%d,%c\n",cnt++,c);
		switch(i)
		{
			case 0:
				{
					if(c=='"')i=1,putchar(c);
					else if(c=='{')i=7,putchar(c);
					else if(c=='/')i=2;
					else putchar(c);
					break;
				}
			case 1:
				{
					if(c=='"')i=6;
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
			        if(c==' '||c==';'||c=='\n')putchar(c),i=0;
			        else if(c=='/')i=2;
			        else putchar(c),i=1;
			    }
		    case 7:
		        {
		            if(c=='}')putchar(c),i=0;
		            else putchar(c);
		        }
		}
	}
	return 0;
}