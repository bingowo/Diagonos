#include<stdio.h>
#include<string.h>
int main()
{
	int i,t,j;
	double x;
	char m[52];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		x=0;char n[150];
		scanf("%s",m);
		for(j=strlen(m)-1;j>1;j--)
		{
			x=(x+((int)m[j]-48))*0.125;
		}
		sprintf(n,"%.147lf",x);
		for(j=strlen(n)-1;j>1;j--)
			if(n[j]!='0')
			{
				n[j+1]='\0';break;
			}
		printf("case #%d:\n%s\n",i,n);
	}
 } 