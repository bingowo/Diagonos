#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	long long t;
	scanf("%lld",&t);
	for(long long m=0;m<t;m++)
	{
		int ans=1,n;scanf("%d",&n);
		int flag=n&1,sum=1,limit=0;
		while(n-(~(~0<<limit))>0)limit++;
		//printf("limit=%d\n",limit);
		for(int i=1;i<limit;i++)
		{
			if(((n>>i)&1)!=flag)
			{
				sum++; 
			}
			else
			{
				sum=1;
			}
			flag=(n>>i)&1;
			ans=ans>sum?ans:sum;
		}
		printf("case #%d:\n%d\n",m,ans);
	}
	return 0;
}
