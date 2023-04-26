#include <stdio.h>
#include <math.h>

typedef long long int lli;


int main(void)
{
	lli n;
	scanf("%lld", &n);
	if(n == 0){
		printf("(0,0)");
	}else{
		lli round = sqrt(n);
		lli ox, oy;
		lli bx;
		lli delta = n - round * round;
		if(round % 2 == 0){
			round /= 2;
			ox = -1 * round;
			oy = -1 * round;
			bx = 1 * round;
			if(delta > bx - ox){
				delta -= (bx - ox);
				ox = bx;
				oy += delta;
			}else{
				ox += delta;
			}
		}else{
			round = (round + 1) / 2;
			ox = 1 * (round - 1);
			oy = 1 * (round - 1) + 1;
			bx = -1 * (round - 1) - 1;
			if(delta > ox - bx){
				delta -= (ox - bx);
				ox = bx;
				oy -= delta;
			}else{
				ox -= delta;
			}
		}
		printf("(%lld,%lld)", ox, oy);
	}
	
	return 0;
}