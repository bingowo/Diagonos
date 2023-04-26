#include<stdio.h>
typedef long long ll; 
ll f(ll x,ll y){
	if(x==y) return 4*x;
	if(x<y){
		ll t=y;
		y=x;
		x=t;
	} 
	return 4*y+f(x-y,y);
}
int main(){
	ll x,y;
	scanf("%lld%lld",&x,&y);
	printf("%lld",f(x,y));
	return 0;
} 