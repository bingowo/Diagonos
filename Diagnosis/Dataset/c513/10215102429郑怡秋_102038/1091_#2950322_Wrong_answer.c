#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	long long a=0,b=0,n=0;
	char c;
	scanf("%lld",&a);
	c=getchar();//printf("%c\n",c);
	if(c=='-') 
	{
		scanf("%lld",&b);
		if(b==0) b=-1;
		else b=-b;
	}
	else if(c=='+')
	{
		scanf("%d",&b);
		if(b==0) b=1;	
	}
	else if(c=='i')
	{
		if(a==0) b=1;
		else b=a,a=0;
	}
	if(b!=0) getchar();
	scanf("%d",&n);
	//printf("%d %d %d",a,b,n);
	long long k=a,l=b;
	for(int i=1;i<n;i++)
	{
		long long p=k;
		k=p*a-b*l;
		l=p*b+l*a;
	}
	if(k!=0&&l>0) printf("%lld+%lldi\n",k,l);
	else if(l<0&&k!=0) printf("%lld%lldi\n",k,l);
	else if(k==0&&l!=0) printf("%lldi\n",l);
	else if(k!=0&&l==0) printf("%lld\n",k);
	return 0;
}