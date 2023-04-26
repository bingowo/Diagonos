#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
char s[105];
int main()
{
	int c3,c2,c1,c0;
	while(scanf("%s",s)!=EOF)
	{
		int n=strlen(s),x=0,sig=1;
		c3=c2=c1=c0=0;
		for(int i=5;i<n;i++)
		{
			if(s[i]>='0'&&s[i]<='9')x=x*10+s[i]-'0';
			if(s[i]=='-'){sig=-1;continue;}
			if(s[i]=='+')continue;
			if(s[i]=='x')
			{
				if(i+1<n&&s[i+1]=='^')
				{
					if(s[i+2]=='3')c3=x?x*sig:sig;
					if(s[i+2]=='2')c2=x?x*sig:sig;
					i+=2;
				}
				else c1=x?x*sig:sig;
				x=0;sig=1;
			}
			if(i==n-1&&s[i]>='0'&&s[i]<='9')c0=x*sig;
		} 
		//printf("%d %d %d %d\n",c3,c2,c1,c0);
		for(int y=20;y>=-20;y--)
		{
			for(int x=-20;x<=20;x++)
			{
				int yy=c3*x*x*x+c2*x*x+c1*x+c0;
				if(yy==y)printf("*");
				else if(y==20&&x==0)printf("^");
				else if(y==0&&x==20)printf(">");
				else if(x==0&&y==0)printf("+");
				else if(x==0)printf("|");
				else if(y==0)printf("-");
				else printf(".");
			}
			printf("\n");
		}
		printf("\n");
	}	
	return 0;
} 