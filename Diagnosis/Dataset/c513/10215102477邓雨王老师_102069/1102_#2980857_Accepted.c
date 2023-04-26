#include<stdio.h>
#include<math.h> 
long long ssqrt(long long x){
	long long m=sqrt(x);
	if(m*m>x) return (long long)(sqrt(x)-1);
	return (long long)sqrt(x);
}
int main(){
	long long a;
	scanf("%lld",&a);
	long long x,y;
	long long m=ssqrt(a);
	if(ssqrt(a)%2==1){
		x=(ssqrt(a)-1)/2,y=(ssqrt(a)+1)/2;
		if(a-m*m>m) x-=m,y-=(a-m*m-m);
		else x-=a-m*m;
	}
	else{
		x=-m/2,y=x;
		if(a-m*m>m) x+=m,y+=(a-m*m-m);
		else x+=a-m*m;
	}
	printf("(%lld,%lld)",x,y);
}