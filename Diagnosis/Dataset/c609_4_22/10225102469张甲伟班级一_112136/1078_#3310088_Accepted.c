#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int tmp[10];
int main()
{
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		printf("case #%d:\n",t);
		int cnt=0;
		char ans[1000];
		for(int i=8;i>=0;i--)
			scanf("%d",&tmp[i]);
		int sig=0;
		for(int i=8;i>=0;i--)
			if(tmp[i]!=0)
			{
				sig=i;
				break;
			}
		for(int i=8;i>=0;i--)
		{
			int a=tmp[i];
			if(a==0)
			{
				if(i==0)
				{
					if(sig==0)
						printf("0\n");
					else
						printf("\n");	
				}
				else
					continue;
			}
			else if(a<0)
			{	
				printf("-");
				a=-a;
				if(i!=0)
				{
					if(a>1)
						printf("%d",a);
				}
				else
					printf("%d",a);
				if(i>0)
				{
					printf("x");
					if(i>1)
					{
						printf("^%d",i);
					}
				}
				else
					printf("\n");
			}
			else 
			{
				if(sig!=i)
					printf("+");
				if(i!=0)
				{
					if(a>1)
						printf("%d",a);
				}
				else
					printf("%d",a);
				if(i>0)
				{
					printf("x");
					if(i>1)
					{
						printf("^%d",i);
					}
				}
				else
					printf("\n");
			}
		}
	}
	return 0;
 } 