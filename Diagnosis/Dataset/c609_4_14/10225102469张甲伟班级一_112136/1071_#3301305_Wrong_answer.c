#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	long long x,y; 
	scanf("%lld%lld",&x,&y);
	if(x==0&&y==0)
		printf("0");
	else if((x+y)%2==0)
		printf("-1");
	else
	{
		long long n=1;
		int cnt=0;
		x=abs(x);y=abs(y);
		long long t=x+y;
		for(int k=0;k<64;k++)
			if(((x>>k)&1)==1)			
				cnt++;
		for(int k=0;k<64;k++)
			if(((y>>k)&1)==1)			
				cnt++;
		int len=0;
		for(int i=1;;i++)
		{
			t/=2;
			if(n>t)
			{
				len=i;
				break;
			}
		}
		int ans=(len>cnt)?len:cnt;
		printf("%d",ans);
	}
	return 0;
 } 