#include <stdio.h>
#include <stdlib.h>

int main()
{

    long long int x,y,temp;

    scanf("%lld %lld",&x,&y);
    
    long long ans=0;
	while(x!=0&&y!=0) {//每次均以为最短边
		
		x=temp;
		x=y;
		y=temp;
		long long a=y/x;
		ans+=4*x*a;
		y%=x;
	}

    printf("%lld",ans);

    return 0;
}
