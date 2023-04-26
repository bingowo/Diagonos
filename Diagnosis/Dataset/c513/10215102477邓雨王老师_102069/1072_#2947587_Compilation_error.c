#include<stdio.h>
int main(){
	long long x,y;
	scanf("%lld%lld",&x,&y);
	if((x+y)%2==0){
		if(x==0&&y==0) printf("0");
		else printf("-1");
	}
	else{
		int count=0;
		while((y-x)!=0){
			count++;
			(y-x)/=2;
		}
		printf("%d",count);
	}
}