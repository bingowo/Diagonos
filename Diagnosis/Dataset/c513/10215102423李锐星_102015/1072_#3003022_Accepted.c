#include <stdio.h>
#include <stdlib.h>

void path(long long x,long long y,int s)
{
	if(s)
	{
		long long d=(1LL<<(s-1));
		if(llabs(x)>llabs(y)){
			if(x>0){
				path(x-d,y,s-1);
				printf("E");
			}
			else{
				path(x+d,y,s-1);
				printf("W");
			}
		}
		else{
			if(y>0){
				path(x,y-d,s-1);
				printf("N");
			}
			else{
				path(x,y+d,s-1);
				printf("S");
			}
		}
	}
}

int main()
{
	long long x,y;
	scanf("%lld %lld",&x,&y);
	long long m,n;
	m=llabs(x);
	n=llabs(y);
	unsigned long long d;
	d=m+n;
	if(d%2==0){
		if(d==0){
			printf("0\n");
		}
		else{
			printf("-1\n");
		}
	}
	else{
		d++;
		unsigned long long len=2;
		int step=1;
		for (int i=0;i<64;i++){
			if(len/2<d&&len>=d){
				break;
			}
			else{
				len*=2;
				step++;
			}
		}
		printf("%d\n",step);
		path(x,y,step);
		printf("\n");
	}
	return 0;
}