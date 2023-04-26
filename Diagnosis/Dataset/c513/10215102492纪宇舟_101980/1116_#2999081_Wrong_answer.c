#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
long long ABS(long long x)
{
	if(x<0)return -x;
	return x;
}
int main()
{
	long long x,y;
	scanf("%lld%lld",&x,&y);
	long long lap=ABS(x)+ABS(y);
	int ans=0;
	if(lap&1)
	{
		while(lap>=1)
		{
			lap>>=1;ans++;
		}
	}
	else ans=-1;
	printf("%d",ans);
	return 0;
}