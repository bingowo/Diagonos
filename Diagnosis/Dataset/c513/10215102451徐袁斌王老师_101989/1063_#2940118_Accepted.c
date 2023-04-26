#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	unsigned long long int x,y,t,k,ans=0;
	scanf("%llu %llu",&x,&y);
	while(x!=0)
	{
		k=x/y;x=x%y;
		ans=ans+4*k*y;
		if(x<y&&x!=0)
		{
			t=x;x=y;y=t;
		}
	}
	printf("%llu",ans);
	return 0;
	
	
 } 