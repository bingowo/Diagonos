#include <stdio.h>
#include <stdlib.h>


int main()
{
	long long x,y;
	scanf("%lld %lld",&x,&y);
	x=llabs(x);
	y=llabs(y);
	unsigned long long d;
	d=x+y;
	if(d%2==0){
		printf("-1\n");
	}
	else{
		d++;
		unsigned long long len=2;
		unsigned long long step=1;
		for (int i=0;i<64;i++){
			if(d<=len&&d>len/2){
				break;
			}
			else{
				len*=2;
				step++;
			}
		}
		printf("%llu\n",step);
	}
	return 0;
}