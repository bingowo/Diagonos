#include <stdio.h>
int main(){
	 long long int x,y;
	scanf("%lld %lld",&x,&y);
	long long int max=0,min=0,rest=0,ans=0;
	if(x>y){
		max=x;min=y;
	}
	else{
		max=y;min=x;
	}
	while(min>0){
		rest=max-min;
		ans+=min*4;
		//printf("test:%llu\n",ans);
		if(rest>min){
			max=rest;
		}
		else{
			max=min;min=rest;
		}
	}
	printf("%lld",ans);
}