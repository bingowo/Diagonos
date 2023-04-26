#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int x,y,t,ans=0;
	scanf("%d %d",&x,&y);
	while(x!=0)
	{
		ans=ans+4*y;
		x=x-y;
		if(x<y&&x!=0)
		{
			t=x;x=y;y=t;
		}
	}
	printf("%d",ans);
	return 0;
	
	
 } 