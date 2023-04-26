#include <stdio.h>
#include <string.h>
#define M 120
int count(char *s)
{	int i,p,c;
	for(i=0;i<strlen(s);i++)
	{	
		for(p=0;p<8;p++)
		{
			if(s[i]>>p&1==1)c++;
		}}
	return c;
}
int gcd(int a,int b)
{	int r;
	while (b)
	{
		r=a%b;a=b;b=r;
	}	
	return a;
}
int main()
{
	long long q,k,m;
	int t,i;
	char s [M];
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		scanf("%s",&s);
		m=count(s);k=strlen(s)*8;
		while((q=gcd(m,k))!=1)
		{
			m/=q;k/=q;
		}
		printf("%d%c%d\n",m,'/',k);
	}	
 } 