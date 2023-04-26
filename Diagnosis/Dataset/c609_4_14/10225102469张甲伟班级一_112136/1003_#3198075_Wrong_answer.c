#include<stdio.h>
int T,ans[1000],t,cnt;
long long n; 
int main()
{
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d",&n);
		int j=0,maxn=1;
		if(n==0)
		{
			printf("0\n");
		}
		while(n)
		{
			t=n%2333;
			n/=2333;
			ans[j++]=t;					
		}
		for(int k=j-1;k>=0;k--)
			printf("%d ",ans[k]);
		printf("\n");
	}
	return 0;
 } 