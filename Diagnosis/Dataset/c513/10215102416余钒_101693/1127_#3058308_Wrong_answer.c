#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL long long
int n;
LL gcd(LL a,LL b){
	if(a<b){
		LL tmp=a;
		a=b,b=tmp;
	}
	if(a%b==0) return b;
	return gcd(b,a%b);
} 
LL a,b;
int main() {
	scanf("%d",&n);
	scanf("%lld/%lld",&a,&b);
	for(int i=2;i<=n;i++){
		LL na,nb;
		scanf("%lld/%lld",&na,&nb);
		a=na*b+a*nb;b=b*nb;
		a/=gcd(a,b);b/=gcd(a,b);
	}
	if(a%b==0) printf("%lld",a/b);
	else printf("%lld/%lld",a,b);
	return 0;
}