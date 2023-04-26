#include <stdio.h>
#include <stdlib.h>

int main()
{

    long long int x,y,temp;

    scanf("%lld %lld",&x,&y);
    
    long long ans=0;
	while(y) {//每次均以为最短边
		long long a=y/x;
		ans+=4*x*a;
		y%=x;
		temp=x;
		x=y;
		y=temp;
	}

    printf("%lld",ans);

    return 0;
}