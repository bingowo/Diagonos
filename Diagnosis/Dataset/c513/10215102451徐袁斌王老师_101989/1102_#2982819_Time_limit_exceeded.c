#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	long long int n,x,y,a=0,b=0,c=0;
	scanf("%lld",&n);
	long long int i=1;
	while(n>=2*i)
	{
		n=n-2*i;
		i++;
		a=a+2;
		a=a%4;
		if(b>0) b=-b;
		else if(b<0) b=-b+1;
		else if(b==0) b=1;
		if(c>0) c=-c-1;
		else if(c<0) c=-c;
		else if(c==0) c=-1;
	}
	if(n<i)
	{
		if(b>0) y=b-n;
		else y=n+b;
		x=c;
	}
	else if(n>i)
	{	
		n=n-i;
		if(c<0) x=n+c;
		else x=c-n;
		if(b>0) y=-b;
		else if(b<0) y=-b+1;
		else if(b==0) y=1;
	}
	else if(n==i)
	{
		x=c;
		if(b>0) y=-b;
		else if(b<0) y=-b+1;
		else if(b==0) y=1;
	}
	printf("(%lld,%lld)",x,y);
	
	
}
