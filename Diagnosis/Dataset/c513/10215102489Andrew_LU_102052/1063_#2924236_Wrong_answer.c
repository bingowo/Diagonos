#include<stdio.h>
int main(){
	int x,y,ans=0;
	scanf("%d%d",&x,&y);
	while(x>0 && y>0){
		if(x==y){
			ans+=4*x;
			break;
		}
		if(x<y){
			int t=x;
			x=y;
			y=t;
		}
		ans+=4*y;
		x=x-y;
	}
	printf("%d",ans);
}