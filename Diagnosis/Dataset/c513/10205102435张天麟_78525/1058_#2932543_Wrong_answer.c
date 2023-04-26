#include<stdio.h>
int main()
{
	char c;
	int inslash=0,instar=0,inquatation=0,slash2=0,singlequatation=0;
	while (scanf("%c",&c)!=EOF)
	{
	    T:
	    if(!singlequatation&&!inquatation&&!inslash&&!instar&&c!='/'&&c!='*')
	    {
	        printf("%c",c);
	    }
		if (singlequatation)
		{
			if (slash2) slash2=0;
			else if (c=='\\') slash2=1;
			else if (c=='\'') singlequatation=0;
			printf("%c",c);
		}
		else if (inquatation)
		{
			if (slash2) slash2=0;
			else if (c=='\\') slash2=1;
			else if (c=='"') inquatation=0;
			printf("%c",c);
		}
		else if (inslash)
		{
			if (c=='\n') 
			{
				inslash=0;
				printf("%c",c);
			}
		}
		else if (instar)
		{
			if (c=='*')
			{
				scanf("%c",&c);
				if (c=='/') instar=0;
				else goto T;
			}
		}
		else
		{
			if (c=='/')
			{
				scanf("%c",&c);
				if (c=='/') inslash=1;
				else if (c=='*') instar=1;
				else
				{
					goto T;
				}
			}
			else 
			{
				if (c=='"') inquatation=1;
				else if (c=='\'') singlequatation=1;
				printf("%c",c);
			}
		}
	}
	return 0;
}