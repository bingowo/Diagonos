#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	char a[10];
	int b[128];
	while(gets(a)!=0)
	{
		if(a[0]=='I')
		{
			int c=0,j=6,d=1;
			if(a[j]=='-') {d=-1;j++;}
			for(;a[j]!='\0';j++)
			{
				c=c*10+a[j]-'0';
			}
			b[a[3]]=c*d;
		}
		else if(a[0]=='M'&&a[1]=='O')
		{
			b[a[4]]=b[a[7]];
		}
		else if(a[0]=='M'&&a[1]=='U')
		{
			b[a[4]]=b[a[4]]*b[a[7]];
		}
		else if(a[0]=='A')
		{
			b[a[4]]=b[a[4]]+b[a[7]];
		}
		else if(a[0]=='S')
		{
			b[a[4]]=b[a[4]]-b[a[7]];
		}
		else if(a[0]=='D')
		{
			b[a[4]]=b[a[4]]/b[a[7]];
		}
		else if(a[0]=='O')
		{
			printf("%d\n",b[a[4]]);
		}
	}
	
}