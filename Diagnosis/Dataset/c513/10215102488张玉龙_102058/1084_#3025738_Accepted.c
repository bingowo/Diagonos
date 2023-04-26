#include<stdio.h>
int main()
{
	long long n,num;
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%lld",&n);
		num=1;
		for(int j=0;j<n;j++)
		{
			num=num*2;
		}
		printf("case #%d:\n%lld\n",i,num);
	}
}