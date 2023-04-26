#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL long long
LL x0,y0,x,y,ansx,ansy;
int n;
LL calc(LL x1,LL y1,LL x2,LL y2){
	LL p1=x1-x2,p2=y1-y2;
	if(p1<0) p1=-p1;
	if(p2<0) p2=-p2;
	if(p1<p2) return p2;
	return p1;
}
int main() {
	scanf("%lld%lld",&x0,&y0);
	scanf("%d",&n);
	scanf("%lld%lld",&ansx,&ansy);
	for(int i=2;i<=n;i++){
		scanf("%lld%lld",&x,&y);
		if(calc(x,y,x0,y0)<calc(ansx,ansy,x0,y0)||(calc(x,y,x0,y0)==calc(ansx,ansy,x0,y0)&&(ansx>x||ansx==x&&ansy>y)))
			ansx=x,ansy=y;
	}
	printf("%lld\n",calc(ansx,ansy,x0,y0));
	printf("%lld %lld",ansx,ansy);
	return 0;
}