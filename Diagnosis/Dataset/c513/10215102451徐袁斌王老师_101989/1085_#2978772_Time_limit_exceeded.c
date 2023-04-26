#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int a,b,fuhao;
	char x[501],y[501];
	while(1)
	{
	scanf("%s",x);
	scanf("%s",y);
	a=strlen(x);
	b=strlen(y);
	if(a!=b)
	{
		if(a<b) fuhao=1;
		else fuhao=0;
	}
	else
	{
		if(strcmp(x,y)<0) fuhao=1;
		else fuhao=0;
	}
	if(fuhao==0)
	{
		for(int i=a-1;i>a-b-1;i--)
		{
			if(x[i]-y[i-a+b]<0)
			{
				x[i]=x[i]-y[i-a+b]+10;
				x[i-1]--;
			}
			else
			{
				x[i]=x[i]-y[i-a+b];
			}
		}
		int i=0;
		while(x[i]==0) i++;
		if(x[i]=='\0') printf("0");
		for(;x[i]!='\0';i++) printf("%d",x[i]);
		printf("\n");
	}
	else
	{
		for(int i=b-1;i>b-a-1;i--)
		{
			if(y[i]-x[i-b+a]<0)
			{
				y[i]=y[i]-x[i-b+a]+10;
				y[i-1]--;
			}
			else
			{
				y[i]=y[i]-x[i-b+a];
			}
		}
		int i=0;
		while(y[i]==0) i++;
		if(y[i]=='\0') printf("0");
		printf("-");
		for(;y[i]!='\0';i++) printf("%d",y[i]);
		printf("\n");
	}
	}
}