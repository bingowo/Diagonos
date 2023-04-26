#include <stdio.h>

int main(){
	long long int x,y;
	scanf("%lld %lld",&x,&y);
	long long int a=0,b=0,rest=0,ans=0;
	while(y){
		a=x/y;
		b=x%y;
		ans+=a*4*y;
		//printf("test:%llu\n",ans);
		y=b;
		x=y;
	}
	printf("%lld",ans);
}