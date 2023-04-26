#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
long long rec(int x)
{
	if(x==1) return 1;
	else if(x==2) return 2;
	else if(x==3) return 4;
	else if(x==4) return 8;
	return rec(x-1)+rec(x-2)+rec(x-3)+rec(x-4);
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
		printf("%lld\n",rec(n));			
	}	
	return 0;
}