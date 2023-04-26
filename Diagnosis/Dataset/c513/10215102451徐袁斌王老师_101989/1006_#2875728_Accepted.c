#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int t,a[10],sum=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		sum=0;
		char b[10000];
		scanf("%s",b);
		int c=strlen(b);
		for(int j=0;j<c;j++)
		{
			if(b[j]=='-')
			{
				b[j]='/';
			}
		}
		for(int j=0;j<c;j++)
		{
			sum=sum+(b[j]-48)*pow(3,c-j-1);
		}
		a[i]=sum;
		
	}
	for(int i=0;i<t;i++)
	{
		printf("case #%d:\n%d\n",i,a[i]);
	}
	
	
	
	

	
	return 0;
	
	
 } 