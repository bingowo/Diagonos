#include <stdio.h>
#include <string.h>
#define M 250
int count(char *s)
{	int i,p,c=0;
	for(i=0;i<strlen(s);i++)
	{	
		for(p=0;p<8;p++)
		{
			if(s[i]>>p&1==1)c++;
		}}
	return c;
}
int gcd(int a, int b) 
{return a ? gcd(b % a, a) : b;}
int main()
{
	int q,k=3,m=2,n;
	int t,i;
	char s [M];
	scanf("%d\n",&t);
	for (i=0;i<t;i++)
	{		
		gets(s);
		m=count(s);k=strlen(s)*8;
		q=gcd(m,k);
		m/=q;k/=q;
		printf("%d%c%d\n",m,'/',k);
	}	
	return 0;
 } 
 