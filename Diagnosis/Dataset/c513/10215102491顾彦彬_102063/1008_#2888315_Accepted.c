#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int T,a,b,count;
	scanf("%d",&T);
	while(T--)
	{
		count=0;
		scanf("%d %d",&a,&b);
		for (int i=0;i<=31;i++)
		{
			if (((a^b)& (1<<i))!=0)
				count+=1;
		}
		printf("%d\n",count);
	}
}