#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int change(int a,char *n)
{	
	int i,m=0,p;
	for(i=strlen(n);i>=0;i--)
	{	if (isdigit(n[i])){p=a-'0';}
		else if (a-'a'>=0){p=a-'a'+10;}
		else{p=a-'A'+10;}
		m+=p*pow(a,i);
	}
	return m;
}
void f(int m,int r)
{
if (m/r){f(m/r,r);printf("d",m%r);}
else {printf("%d",m%r);}
}
int main()
{
	int a,b;
	char n[8];
	scanf("%d %s %d",&a,&n,&b);
	f(change(a,n),b);
	return 0;
}