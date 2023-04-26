#include <stdio.h>
#include <string.h>
#define M 120
int count(char *s)
{	int i,p,c=0;
	for(i=0;s[i]!='\0';i++)
	{	
		for(p=0;p<8;p++)
		{
			if(s[i]>>p&1==1)c++;
		}}
	return c;
}
int gcd(int a, int b) {return a ? gcd(b % a, a) : b;}
int main()
{
	long long q,k,m;
	int t,i;
	char s [M];
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		scanf("%s",s);
		m=count(s);k=strlen(s)*8;
		printf("%d\n",m);
		q=gcd(m,k);
		m/=q;k/=q;
		printf("%d%c%d\n",m,'/',k);
	}	
 } 