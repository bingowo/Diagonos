#include<stdio.h>

int main()
{
	long long t,n,r;
	scanf("%d",&t);
	while(t--)
	{
		int num[64],p=0; 
		scanf("%lld%lld",&n,&r);
		if(n<0)
		{
			printf("%c",'-');n=-n;
		}
		if(n==0)printf("%d",0);
		while(n!=0)
		{
			num[p++]=n%r;
			n/=r;
		}
		for(int i=p-1;i>=0;i--)
		{
			if(num[i]>9)
			printf("%c",num[i]+'A'-10);
		else printf("%d",num[i]);
		}
		printf("\n");
	}
	return 0;
}