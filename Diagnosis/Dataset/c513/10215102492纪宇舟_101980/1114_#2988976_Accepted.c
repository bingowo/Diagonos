#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
char s[205];
int main()
{
	int a=0,b=0,c=0,x=0,sig=1;
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')x=x*10+s[i]-'0';
		if(s[i]=='-'){sig=-1;continue;}
		if(s[i]=='+')continue;
		if(s[i]=='x')
		{
			if(i+1<n&&s[i+1]=='^')
			{
				if(s[i+2]=='2')a=x?x*sig:sig;
				i+=2;
			}
			else b=x?x*sig:sig;
			x=0;sig=1;
		}
		if(i==n-1&&s[i]>='0'&&s[i]<='9')c=x*sig;
	} 
	int a1,a2,c1,c2,ans=0;
	for(int i=1;i<=sqrt(a)&&ans==0;i++)
	{
		int j=a/i;if(i*j!=a||j<i)continue;
		for(int k=-200;k<=200&&ans==0;k++)
		for(int l=-200;l<=200&&ans==0;l++)
		{
			if(i==j&&l<k)l=k;
			if(l*k!=c)continue;
			if(i*l+j*k==b)
			{
				ans=1;a1=i;a2=j;c1=k;c2=l;
			}
		}
	}
	if(ans)printf("%d %d %d %d",a1,c1,a2,c2);
	else printf("No Answer!");
	return 0;
}