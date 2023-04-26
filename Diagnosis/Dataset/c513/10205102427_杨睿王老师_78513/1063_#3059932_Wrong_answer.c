#include <stdio.h>
int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	int max=0,min=0,rest=0,ans=0;
	if(x>y){
		max=x;min=y;
	}
	else{
		max=y;min=x;
	}
	while(min>0){
		rest=max-min;
		ans+=min*4;
		if(rest>min) max=rest;
		else max=min;min=rest;
	}
	printf("%d",ans);
}