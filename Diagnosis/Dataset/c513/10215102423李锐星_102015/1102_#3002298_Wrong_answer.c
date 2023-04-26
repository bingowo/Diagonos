#include <stdio.h>
#include <math.h>

int main()
{
	long long n;
	scanf("%lld",&n);
	long long m;
	m=sqrt(n);
	long long d=n-m*m;
	long long a,b,len;
	long long x,y;
	len=m;
	if(m%2==1){
		a=m/2;
		b=a+1;
		if(d<=m){
			y=b;
			x=a-d;
		}
		else{
			x=a-m;
			d-=m;
			y=b-d;
		}
	}
	else{
		a=-(m/2);
		b=a;
		if(d<=m){
			y=b;
			x=a+d;
		}
		else{
			x=a+m;
			d-=m;
			y=b+d;
		}
	}
	printf("(%lld,%lld)\n",x,y);
	return 0;
}