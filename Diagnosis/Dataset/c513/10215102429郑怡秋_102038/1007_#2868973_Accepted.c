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
		long long z=n;
		int ans=1;
		int an=1;
		
		while(n>>1)
		{
			int x=n&1;
			int y=(n>>1)&1;
			if(x!=y) ans++;
			
			n>>=1;
			if(x==y) break;
		}
		while(n>>1)
		{
			int x=n&1;
			int y=(n>>1)&1;
			if(x!=y) an++;
			else if(x==y)
			{
				ans=(ans>an)?ans:an;
				an=1;
			}
			
			n>>=1;
		}
		ans=(ans>an)?ans:an;
		printf("case #%d:\n%d\n",i,ans);
	}
	return 0;
}