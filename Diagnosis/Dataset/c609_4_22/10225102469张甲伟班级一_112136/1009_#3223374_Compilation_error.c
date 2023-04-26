#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
int n;
char s[130];
int cnt1;
int cnt0;
int find1(char c)
{
	int a=c,cnta=0;
	if(a>=0) 
	{
		for(int k=0;k<8;k++)
		if(((a>>k)&1)==1)			
			cnta++;
	}
	else
	{
		for(int k=0;k<16;k++)
		if(((a>>k)&1)==1)			
			cnta++;
	}
	return cnta;
}
int find0(char c)
{
	int a=c,cnta=0;
	if(a>=0) 
	{
		for(int k=0;k<8;k++)
		if(((a>>k)&1)==0)			
			cnta++;
	}
	else
	{
		for(int k=0;k<16;k++)
		if(((a>>k)&1)==0)			
			cnta++;
	}
	return cnta;
}
int measure(int x, int y)
{	
	int z = y;
	while(x%y!=0)
	{
		z = x%y;
		x = y;
		y = z;	
	}
	return z;
}
int main()
{
	scanf("%d",&n);
	char c=getchar();
	while(n--)
	{
		cnt1=0,cnt0=0;
		gets(s);                         
		for(int i=0;s[i]!='\0';i++)
		{
			cnt1=cnt1+find1(s[i]);
			cnt0=cnt0+find0(s[i]);
		}
		int yueshu=measure(cnt1,cnt0+cnt1);
		int a=cnt1/yueshu,b=(cnt1+cnt0)/yueshu;
		printf("%d/%d\n",a,b);
	}
	return 0;
}