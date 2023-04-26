#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	char a[10000];
	long long int b[128]={0};
	while(gets(a)!=0)
	{
		if(a[0]=='I')
		{
			long long int c=0,j=6,d=1;
			if(a[j]=='-') {d=-1;j++;}
			for(;a[j]!='\0';j++)
			{
				c=c*10+a[j]-'0';
			}
			b[a[3]]=c*d;
		}
		else if(a[0]=='M'&&a[1]=='O'&&a[2]=='V')
		{
			b[a[4]]=b[a[7]];
		}
		else if(a[0]=='M'&&a[1]=='U')
		{
			if(a[9]!=',') b[a[4]]=b[a[4]]*b[a[7]];
			else b[a[4]]=b[a[10]]*b[a[7]];
		}
		else if(a[0]=='A'&&a[1]=='D')
		{
			if(a[9]!=',') b[a[4]]=b[a[4]]+b[a[7]];
			else b[a[4]]=b[a[10]]+b[a[7]];
		}
		else if(a[0]=='S')
		{
			if(a[9]!=',') b[a[4]]=b[a[4]]-b[a[7]];
			else b[a[4]]=b[a[7]]-b[a[10]];
		}
		else if(a[0]=='D')
		{
			if(a[9]!=',') b[a[4]]=b[a[4]]/b[a[7]];
			else b[a[4]]=b[a[7]]/b[a[10]];
		}
		else if(a[0]=='X'&&a[1]=='C')
		{
			long long int c=0;
			c=b[a[5]];
			b[a[5]]=b[a[8]];
			b[a[8]]=c;
		}
		else if(a[0]=='O'&&a[1]=='U')
		{
			printf("%lld\n",b[a[4]]);
		}
		else if(a[0]=='M'&&a[1]=='O'&&a[2]=='D')
		{
			if(a[9]!=',') b[a[4]]=b[a[4]]%b[a[7]];
			else b[a[4]]=b[a[7]]%b[a[10]];
		}
		else if(a[0]=='A'&&a[1]=='N')
		{
			if(a[9]!=',') b[a[4]]=b[a[4]]&b[a[7]];
			else b[a[4]]=b[a[7]]&b[a[10]];
		}		
		else if(a[0]=='X'&&a[1]=='O')
		{
			if(a[9]!=',') b[a[4]]=b[a[4]]^b[a[7]];
			else b[a[4]]=b[a[7]]^b[a[10]];
		}
		else if(a[0]=='O'&&a[1]=='R')
		{
			if(a[8]!=',') b[a[3]]=b[a[3]]|b[a[6]];
			else b[a[3]]=b[a[6]]|b[a[9]];			
		}
	}
	
}