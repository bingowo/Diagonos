#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	long long t;
	scanf("%lld",&t);
	for(long long m=0;m<t;m++)
	{
		int a,b,ans=0;scanf("%d%d",&a,&b);
		for(int i=0;i<32;i++)
		{
			if(((a>>i)&1)!=((b>>i)&1))ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

