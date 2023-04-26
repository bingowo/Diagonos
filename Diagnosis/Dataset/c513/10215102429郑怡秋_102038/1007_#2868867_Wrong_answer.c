#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	long long n;
	int T;
	scanf("%d",&T);
	int i;
	for(i=0;i<T;i++)
	{
		scanf("%lld",&n);
		int ans=0;
		int an=0;
		int k=1;
		while(n)
		{
			int x=n&1;
			int y=(n>>1)&1;
			if(x!=y && k==2) an++;
			if(x!=y && k==1) ans++;
			else k=2;
			n>>=1;
		}
		ans=(ans>an)?ans:an;
		printf("case #%d:\n%d\n",i,ans);
	}
	return 0;
}