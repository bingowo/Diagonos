#include<stdio.h>
#include<string.h>
int main()
{
	int i,t,j,result;
	char a[22];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		result=0;
		scanf("%s",a);
		for(j=0;j<strlen(a);j++)
		{
			if(a[j]=='1')result++;
			else if(a[j]=='-')result--;
			if(j!=strlen(a)-1)result*=3;
		}
		printf("case #%d:\n%d\n",i,result);
	}
	
 } 