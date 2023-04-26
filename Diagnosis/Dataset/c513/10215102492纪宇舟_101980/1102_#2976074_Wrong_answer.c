#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
long long cal(long long x)
{
	return 4*x*(x+1);
}
int main()
{
	long long x,left;scanf("%lld",&x);
	long long n=sqrt(((double)x)/4);
	if(cal(n)<x&&cal(n+1)>=x)n=n+1;
	else if(cal(n-1)<x&&cal(n)>=x)n=n;
	else n=n+2;
	//printf("%lld\n",n);
	left=x-cal(n-1);
	if(left<=2*n)printf("(%lld,%lld)",n-left,n);
	else if(left<=4*n)printf("(%lld,%lld)",-n,n-(left-2*n));
	else if(left<=6*n)printf("(%lld,%lld)",-n+(left-4*n),-n);
	else printf("(%lld,%lld)",n,-n+(left-6*n));
	return 0;
} 