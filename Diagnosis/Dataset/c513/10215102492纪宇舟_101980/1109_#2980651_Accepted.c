#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
	int ct=0,T;scanf("%d",&T);
	while(T--)
	{
		int out=0,x;
		printf("case #%d:\n",ct++);
		for(int i=8;i>=0;i--)
		{
			scanf("%d",&x);
			if(x!=0)
			{
				if(x>0)
				{
					if(out)printf("+");
					if(i==0||x!=1)printf("%d",x);
				}
				else 
				{
					if(i==0||x!=-1)printf("%d",x);
					else printf("-");
				}
				if(i>1)printf("x^%d",i);
				if(i==1)printf("x");
				out=1;
			}
		}
		if(out==0)printf("0");printf("\n");
	}
} 