#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define M 1000000007 
long long n,res,p;

int main() {
	scanf("%lld",&n);
	p=(long long)sqrt(n/7*2-1<0?0:n/7*2-1);
	while(n >= (7+7*p)*p/2) p++;
	p--;
	res=n-p*(7*p+7)/2;
	p++;
	//printf("%lld %lld\n",p,res);
	if(res<=p) printf("(%lld,%lld)",p-1,res),exit(0);
	res-=p;
	if(res<=p*2-1) printf("(%lld,%lld)",p-res-1,p),exit(0);
	res-=p*2-1;
	if(res<=p*2) printf("(%lld,%lld)",-p,p-res),exit(0);
	res-=p*2;
	if(res<=p*2) printf("(%lld,%lld)",-p+res,-p),exit(0);
	res-=p*2;
	printf("(%lld,%lld)",p,-p+res);
	return 0;
}
