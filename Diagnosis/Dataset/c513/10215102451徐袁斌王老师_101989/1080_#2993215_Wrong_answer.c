#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void add(int a[],int b)
{
	int c=0,i=98;
	a[99]=a[99]+b;
	c=a[99]/10;a[99]=a[99]%10;
	while(c)
	{
		a[i]=a[i]+c;
		c=a[i]/10;a[i]=a[i]%10;
	}
}
void time(int b[])
{
	int c=0;
	for(int i=100;i>=0;i--)
	{
		b[i]=b[i]*2+c;
		if(b[i]>=10) c=b[i]/10;
		else c=0;
		b[i]=b[i]%10;
	}
}
void f(char a[],int b)
{
	int c=0,d=0;
	for(int i=0;i<b;i++)
	{
		if(a[i]%2==1) d=1;
		else d=0;
		a[i]=(c*10+a[i])/2;
		c=d;
	}
}
int g(char a[],int b)
{
	int c=0;
	for(int i=0;i<b;i++)
	{
		if(a[i]!=0) c++;
	}
	if(c!=0) return 1;
	else return 0;
}
int main()
{
	int t,a[335],b[101];
	char s[101]; 
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%s",s);
		int d=strlen(s);
		for(int j=0;j<101;j++) {b[j]=0;}
		for(int j=0;j<334;j++) {a[j]=0;}
		for(int j=0;s[j]!='\0';j++) s[j]=s[j]-'0';
		int j=0,x=1;
		while(x!=0)
		{
			if(s[d-1]%2==1)	a[j]=1;
			else a[j]=0;
			j++;
			f(s,d);
			x=g(s,d);
		}
		for(int k=0;k<j;k++)
		{
			time(b);
			add(b,a[k]);
		}
		printf("case #%d:\n",i);
		int k=0;
		while(b[k]==0&&k<100) k++;
		if(k==100) printf("%d\n",b[k]);
		else
		{
			for(;k<100;k++) printf("%d",b[k]);
			printf("\n");
		}
	}

	
}