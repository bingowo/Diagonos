#include<stdio.h>
int main(){
	long long x,y;
	long long ans=0;
	scanf("%lld%lld",&x,&y);
	while(x>0 && y>0){
		if(x==y){
			ans+=4*x;
			break;
		}
		if(x<y){
			long long t=x;
			x=y;
			y=t;
		}
		ans+=4*y*(x/y);
		x=x-y*(x/y);
	}
	printf("%lld",ans);
}