#include <stdio.h>
#inlcude <string.h>
#include <ctype.h>
#include <ctype.h>
void change(int a,char *s)
{	
	int i,m=0,p,q;
	for(i=0;i<strlen(s);i++)
	{	if (isdigit(s[i])){p=s[i]-'0';}
		else{p=-1;}
		m=m*a+p;
	}
	printf("%d",m);
}
int main()
{
	int t,i,m;
	char a[100];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%s",&a);
		for (m=0;a[m]!='\0';m++)
		{	printf("case #%d:\n",i);
			change(10,a);
		}
	}
	
}