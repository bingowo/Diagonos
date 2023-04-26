#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
unsigned long long rec(int x)
{
	if(x<=0) return 0;
	else if(x==1) return 1;
	else if(x==2) return 2;
	else if(x==3) return 4;
	else if(x==4) return 8;
	unsigned long long x1=1,x2=2,x3=4,x4=8;
	for(int i=5;i<=x;i++)
	{
		unsigned long long x0=x1;
		x1=x2;
		x2=x3;
		x3=x4;
		x4=x0+x1+x2+x3;
	}
	return x4;
}
int main()
{
	int x;
	scanf("%d",&x);
	for(int i=0;i<x;i++)
	{
		int n=0;
		scanf("%d",&n);
		printf("case #%d:\n",i);
		printf("%llu\n",rec(n));			
	}	
	return 0;
}