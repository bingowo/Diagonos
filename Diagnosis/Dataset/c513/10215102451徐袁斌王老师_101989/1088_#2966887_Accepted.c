#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long int f(int m,int n)
{
	if(n>m-n) n=m-n;
	if(n==0) return 1;
	else if(m<=20)
	{
		long long int a=1,b=1;
		for(int i=m,k=0;k<n;i--,k++)
		{
			a=a*i;
		}
		for(int j=1;j<=n;j++)
		{
			b=b*j;
		}
		return a/b;
	}
	else
	{
		return f(m-1,n-1)+f(m-1,n);
	}
	
}
int main()
{
	int t,m,n;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d%d",&m,&n);
		if(n>m-n) n=m-n;
		printf("case #%d:\n",i);
		printf("%lld\n",f(m,n));
	}
	return 0;
}