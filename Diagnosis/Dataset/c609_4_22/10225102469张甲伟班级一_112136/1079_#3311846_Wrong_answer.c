#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int a,b,c,a1=1,c1=-200,a2,c2;
char s[100];
int main()
{
	scanf("%s",s);
//读取a,b,c 
	int i;
	for(i=0;s[i]!='x';i++)
		;
	int tap=i-1;
	if(tap<0)
		a=1;
	else
		for(int j=0;j<=tap;j++)
			a=a*10+s[j]-'0';
	for(i;s[i]!='+'&&s[i]!='-'&&s[i]!='\0';i++)
		;
	if(s[i]=='\0')
	{
		b=0;
		c=0;
	}
	else
	{
		int sign;
		if(s[i]=='+')	
			sign=1;
		else
			sign=-1;
		tap=i+1;
		for(i;s[i]!='x'&&s[i]!='\0';i++)
			;
		if(s[i]=='\0')
		{
			for(int j=tap;j<=i-1;j++)
				c=c*10+s[j]-'0';
			c=sign*c;
		}
		else
		{
			for(int j=tap;j<=i-1;j++)
				b=b*10+s[j]-'0';
			b=sign*b;
			for(i;s[i]!='+'&&s[i]!='-'&&s[i]!='\0';i++)
				;
			if(s[i]!='\0')
			{
				tap=i+1;
				if(s[i]=='+')	
					sign=1;
				else
					sign=-1;
				for(i;s[i]!='\0';i++)
					;
				for(int j=tap;j<=i-1;j++)
					c=c*10+s[j]-'0';
				c=sign*c;
			}
		}
	}
//遍历 求系数 
	int sig=0;
	if(b*b-4*a*c<0)
		;
	else
		for(a1=1;a1<200;a1++)
			for(a2=a1;a2<200;a2++)
				if(a1*a2==a)
				{
//					printf("%d %d\n",a1,a2);
					for(c1=-200;c1<=200;c1++)
						for(c2=c1;c2<=200;c2++)
						if(c1*c2==c)
						{
//							printf("%d %d\n",c1,c2);
							if(a1*c2+a2*c1==b)
							{
								sig=1;
								printf("%d %d %d %d",a1,c1,a2,c2);
								break;
							}	
						}
				}
	if(sig==1)
		;
	else
		printf("No Answer!");
	return 0;
}