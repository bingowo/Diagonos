#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>

int main()
{
	unsigned long long x,y;
	scanf("%llu%llu",&x,&y);
	unsigned long long ans=0;
	if(x==y) ans=4*y;
	else if(x>y)
	{
		while(y>0)
		{
			ans+=4*y;
			unsigned long long z1=y,z2=x-y;
			if(z1>z2) x=z1,y=z2;
			else x=z2,y=z1;
			
		}
	}
	printf("%llu\n",ans);
	return 0;
}