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
		while(n)
		{
			int x=n&1;
			int y=(n>>1)&1;
			if(x!=y) ans++;
			if(x==y) ans=0;
			n>>=1;
		}
		printf("case #%d:\n%d\n",i,ans);
	}
	return 0;
}