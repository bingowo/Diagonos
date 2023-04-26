#include<stdio.h>
typedef long long ll; 
ll f(ll x,ll y){
	if(x*y==0) return 0;
	if(x<y){
		ll t=y;
		y=x;
		x=t;
	} 
	return 4*y*(x/y)+f(x-y*(x/y),y);
}
int main(){
	ll x,y;
	scanf("%lld%lld",&x,&y);
	printf("%lld",f(x,y));
	return 0;
} 