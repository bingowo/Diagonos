#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef long long LL;
LL ABS(LL x)
{
	if(x<0)return -x;
	return x;
}
LL MAX(LL x,LL y)
{
	if(x>y)return x;return y;
}
int main()
{
	LL x0,y0,desx,desy,x,y,dis,ans=-1;int n;
	scanf("%lld%lld%d",&x0,&y0,&n);
	while(n--)
	{
		scanf("%lld%lld",&x,&y);
		dis=MAX(ABS(x-x0),ABS(y-y0));
		if(dis==ans)
		{
			if(x==desx)
			{
				if(y<desy)
				{
					desx=x;desy=y;
				}
			}
			else if(x<desx){desx=x;desy=y;}
		}
		else if(dis<ans||ans==-1){desx=x;desy=y;ans=dis;}
	}
	printf("%lld\n%lld %lld",ans,desx,desy);
	return 0;
}