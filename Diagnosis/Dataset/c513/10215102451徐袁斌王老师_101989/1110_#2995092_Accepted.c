#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	char a[100],b;
	int x=0,y=0,d=1,ans=0,i=0;
	scanf("%s",a);
	for(;a[i-1]!='=';i++)
	{
		if(a[i]=='+'||a[i]=='=')
		{
			y+=ans*d;d=1;ans=0;
		}
		else if(a[i]=='-')
		{
			y+=ans*d;d=-1;ans=0;
		}
		else if(a[i]>='0'&&a[i]<='9')
		{
			while(a[i]>='0'&&a[i]<='9')
			{
				ans=ans*10+a[i]-'0';
				i++;
			}
			i--;
		}
		else
		{
			b=a[i];
			if(i==0) x+=1;
			else if(a[i-1]=='-'||a[i-1]=='+')
			{
				x+=d;
			}
			else
			{
				x+=ans*d;
			}
			ans=0;
		}
	}
	d=1;
	for(;a[i-1]!='\0';i++)
	{
		if(a[i]=='+'||a[i]=='\0')
		{
			y-=ans*d;d=1;ans=0;
		}
		else if(a[i]=='-')
		{
			y-=ans*d;d=-1;ans=0;
		}
		else if(a[i]>='0'&&a[i]<='9')
		{
			while(a[i]>='0'&&a[i]<='9')
			{
				ans=ans*10+a[i]-'0';
				i++;
			}
			i--;
		}
		else
		{
			b=a[i];
			if(a[i-1]=='=') x-=1;
			else if(a[i-1]=='-'||a[i-1]=='+')
			{
				x-=d;
			}
			else
			{
				x-=ans*d;
			}
			ans=0;
		}		
	}
	printf("%c=%.3f",b,-y*1.0/x);
}