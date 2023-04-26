#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fenzi(char a);
int GCD(int a,int b);

int main(){
	int n;
	scanf("%d\n",&n);
	int i=0;
	for(i;i<n;i++)
	{
		char s[250];
		int d=0;
		for(;d<130;d++)
		{
			char m=getchar();
			if (m=='\n') break;
			s[d]=m;
		}
		int a=0,b;
		b=8*strlen(s);
	
		int j=0;
		for(j;j<strlen(s);j++)
		{
			a+=fenzi(s[j]);
		}

		int c=GCD( a, b);
		printf("%d/%d\n",a/c,b/c);
	}
	
	return 0;
}
int fenzi(char a)
{
	int x=1,p=0,r=0;
	for(;r<8;r++)
	{
		if(a&x) p++;
		x=x<<1;
	}
	return p;
}
int GCD(int a,int b)
{
	int r;
	while (b>0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
