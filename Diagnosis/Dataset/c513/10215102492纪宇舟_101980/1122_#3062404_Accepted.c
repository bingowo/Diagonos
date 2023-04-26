#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
int main()
{
	int t;scanf("%d",&t);
	int cnt,ans[100];
	long long x;
	while(t--)
	{
		scanf("%lld",&x);
		cnt=0;
		do
		{
			ans[++cnt]=x%2333;
			x/=2333;
		}while(x!=0);
		for(int i=cnt;i>=1;i--)
		{
			printf("%d",ans[i]);
			if(i!=1)printf(" ");
		}
		if(t!=0)printf("\n");
	}
	return 0;
} 