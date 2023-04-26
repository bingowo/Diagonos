#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	unsigned long long int x,y,t,ans=0;
	scanf("%llu %llu",&x,&y);
	while(x!=0)
	{
		ans=ans+4*y;
		x=x-y;
		if(x<y&&x!=0)
		{
			t=x;x=y;y=t;
		}
	}
	printf("%llu",ans);
	return 0;
	
	
 } 