#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef unsigned long long ULL;
int main()
{
	ULL x,y,ans=0;
	scanf("%llu%lld",&x,&y);
	while(x!=0&&y!=0)
	{
		if(x>y)
		{
			ans+=y;
			x-=y;
		}
		else 
		{
			ans+=x;
			y-=x;
		}
	}
	printf("%llu",4*ans);
	return 0;
}