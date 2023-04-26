#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
   char s[100];
   scanf("%s",s);
   double a=0,b=0;
   char k;
   int ceof;
	int sign=1;
	int i=0;
	int flag=1;
	while(s[i])
	{
		ceof=0,sign=1;
		if(s[i]=='+')
		{
			sign=1;
			i++;
		}
		else if(s[i]=='-')
		{
			sign=-1;
			i++;
		}
		if(s[i]>='a'&&s[i]<='z')
		{
			k=s[i];
			ceof=1;
			i++;
			if(flag)
				a+=sign*ceof;
			else
				a-=sign*ceof;
			continue;
		}
		else if(s[i]>='0'&&s[i]<='9')
		{
			while(s[i]>='0'&&s[i]<='9')
			{
				ceof=ceof*10+s[i]-'0';
				i++;
			}
			if(s[i]>='a'&&s[i]<='z')
			{
				k=s[i];
				if(flag)
					a+=sign*ceof;
				else
					a-=sign*ceof;
				i++;
			}
			else
			{
				if(flag)
					b-=sign*ceof;
				else
					b+=sign*ceof;
				continue;
			}
		}
		if(s[i]=='=')
		{
			flag=0;
			i++;
		}
	}
   printf("%c=%.3f\n",k,b/a);
}
