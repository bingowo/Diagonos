#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int m=0;
void add(int a[],int b[])
{   int i;
    for(i=101;i>=0;i--)
    {
        a[i] += b[i];
        a[i-1] += a[i]/10;
        a[i] %= 10;
    }
}
void f(int a[])
{
	int b[101]={0},d=0;
	for(int i=0;i<101;i++)
	{
		for(int j=0;j<101;j++) b[j]=0;
		if(a[i]==9)
		{
			b[i-1]=1;
			add(a,b);
			for(int j=i;j<101;j++) a[j]=0;
			f(a);
		}
	}
	d=(a[0]*10+a[1])%9;
	for(int i=2;i<=m;i++)
	{
		d=(d*10+a[i])%9;
	}
	if(d==0)
	{
		for(int j=0;j<101;j++) b[j]=0;
		b[m]=1;add(a,b);
		f(a);
	}
}
int main()
{
	char s[101];
	int a[101]={0},b[101]={0};
	scanf("%s",s);
	for(int i=0;s[i]!='\0';i++)
	{
		a[i+1]=s[i]-'0';m++;
	}
	b[m]=1;
	add(a,b);
	
	f(a);
	int j=0;
	if(a[j]==0) j++;
	for(;j<=m;j++)
	{
		printf("%d",a[j]);
	}
}