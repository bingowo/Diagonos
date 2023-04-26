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
	a=k;b=l;
	if(n==0) printf("1\n");
	else if(b==0) printf("%lld",a);
	else if(a==0) {
		if(b==1) printf("i");
		else if(b==-1) printf("-i");
		else if(b==0) printf("0");
		else printf("%lldi",b);
	}
	else if(b==1) printf("%lld+i",a);
	else if(b==-1) printf("%lld-i",a);
	else if(a>0&&b>0 ||(a<0&&b>0)) printf("%lld+%lldi",a,b);
	else if(a<0&&b<0 ||(a>0&&b<0)) printf("%lld%lldi",a,b);
	
	return 0;
}