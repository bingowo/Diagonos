#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void f(int a)
{
	if(a==0) 
	{
		printf("0000000000");
	}
	else
	{
		int sum=0;
		while(a!=0)
		{
			sum=sum*10+a%2;
			a=a/2;
		}
		int cnt=1;
		for(int j=1;;)
		{
			if(sum>j && sum<j*10-1) break;
			j=j*10;
			cnt++;
		}
		cnt=10-cnt;
		for(;cnt!=0;cnt--)
		{
			printf("0");
		}
		printf("%d",sum);
		}
}

void f1(int a)
{
	if(a==0) 
	{
		printf("0000");
	}
	else
	{
		int sum=0;
		while(a!=0)
		{
			sum=sum*10+a%2;
			a=a/2;
		}
		int cnt=1;
		for(int j=1;;)
		{
			if(sum>j && sum<j*10-1) break;
			j=j*10;
			cnt++;
		}
		cnt=4-cnt;
		for(;cnt!=0;cnt--)
		{
			printf("0");
		}
		printf("%d",sum);
		}
}

void f2(int a)
{
	if(a==0) 
	{
		printf("0000000");
	}
	else
	{
		int sum=0;
		while(a!=0)
		{
			sum=sum*10+a%2;
			a=a/2;
		}
		int cnt=1;
		for(int j=1;;)
		{
			if(sum>j && sum<j*10-1) break;
			j=j*10;
			cnt++;
		}
		cnt=7-cnt;
		for(;cnt!=0;cnt--)
		{
			printf("0");
		}
		printf("%d",sum);
		}
}

void convert(char *p,int len)
{
	if(len%3==0)
	{
		char s[3];
		for(int i=0;i<len;i=i+3)
		{
			s[0]=p[i];
			s[1]=p[i+1];
			s[2]=p[i+2];
			int m=atoi(s);
			f(m);
		}		
	}
	else if(len%3==1)
	{
		char s[3];
		for(int i=0;i<len-1;i=i+3)
		{
			s[0]=p[i];
			s[1]=p[i+1];
			s[2]=p[i+2];
			int m=atoi(s);
			f(m);
		}
		int m=p[len-1];
		f1(m);		
	}
	else
	{
		char s[3];
		for(int i=0;i<len-2;i=i+3)
		{
			s[0]=p[i];
			s[1]=p[i+1];
			s[2]=p[i+2];
			int m=atoi(s);
			f(m);
		}
		int m=p[len-2];
		int n=p[len-1];
		n=m*10+n;
		f2(n);		
	}
}

int main()
{
	char s[501];
	scanf("%s",s);
	int len=strlen(s);
	char *p=s;
	printf("0001");
	f(len);
    convert(p,len);
    return 0;
}