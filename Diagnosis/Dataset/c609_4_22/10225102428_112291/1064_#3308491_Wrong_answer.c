
#include<stdio.h>
int main() {
	long long int x,y;
	scanf("%d%d",&x,&y);
	long long int t;
	if(x>y){
	    t=x;
	    x=y;
	    y=t;
	}
	long long int ans=0;
	while(x) {//每次均以为最短边
		long long int a=y/x;
		ans+=4*x*a;
		y%=x;
		t=x;
	    x=y;
	    y=t;
	}
	printf("%d",ans);
	return 0;
}
