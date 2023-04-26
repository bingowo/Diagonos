#include <stdio.h>

int main(){
	long long int x,y;
	scanf("%lld %lld",&x,&y);
	long long int a=0,b=0,ans=0;
	while(y>0){
		a=x/y;
		b=x%y;
		ans+=a*4*y;
		//printf("test:%llu\n",ans);
		x=y;
		y=b;
	}
	printf("%lld",ans);
}