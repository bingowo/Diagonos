#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int x;
		scanf("%d",&x);
		unsigned long long a0=0,a1=1,a2=1;
		if(x==0) a2=0;
		else if(x==1||x==2) a2=1;
		else
			for(int n=2;n<x;n++)
			{
				unsigned long long a=a0;
				a0=a1;
				a1=a2;
				a2=a+a0+a1;
			}
		
		printf("case #%d:\n%llu\n",i,a2);
	}
	return 0;
 } 