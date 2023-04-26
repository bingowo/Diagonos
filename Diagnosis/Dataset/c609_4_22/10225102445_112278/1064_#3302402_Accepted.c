#include<stdio.h>
int main() {
	long long int x,y,t;
	scanf("%lld %lld",&x,&y);
	if(x>y){t=x;x=y;y=t;}
		
	long long int ans=0;
	while(x!=0) {//每次均以为最短边
		long long int a=y/x;
		ans+=4*x*a;
		y%=x;
		t=x;x=y;y=t;
	}
	printf("%lld",ans);
	return 0;
}