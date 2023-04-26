#include<stdio.h>
long long T,ans[1000],t;
long long n; 
int main()
{
	scanf("%lld",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%lld",&n);
		int j=0;
		if(n==0)
		{
			printf("0");
		}
		while(n)
		{
			t=n%2333;
			n/=2333;
			ans[j++]=t;					
		}
		for(int k=j-1;k>=0;k--)
			printf("%lld ",ans[k]);
		printf("\n");
	}
	return 0;
 } 