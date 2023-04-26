#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void add(int a[],int b)
{
	int c=b;
	for(int i=99;i>=0;i--)
	{
		a[i]=a[i]+c;
		if(a[i]>=10)
		{
			c=a[i]/10;a[i]=a[i]%10;
		}
		else break;
	}
}
int f(int a,int b[])
{
	if(a==0) return 1;
	else
	{
		return b[a-1]*f(a-1,b);
	}
}
int main()
{
	int d,a[100],b[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};
	char s[100];
	scanf("%s",s);
	d=strlen(s);
	for(int i=0;i<100;i++) a[i]=0;
	for(int i=d-1,j=0;i>=0;i--,j++)
	{
		int ans=0;
		ans=ans+s[i]-'0';
		if(s[i-1]!=','&&i!=0)
		{
			ans=ans+(s[i-1]-'0')*10;
			i--;
		}
		add(a,ans*f(j,b));
		i--;
	}
	int i=0;
	while(a[i]==0&&i<99) i++;
	if(i==99) printf("%d",a[i]);
	else
	{
		for(;i<=99;i++) printf("%d",a[i]);
	}
}