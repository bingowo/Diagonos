#include<stdio.h>
#include<math.h>
int main(){
	long long x,y;
	scanf("%lld%lld",&x,&y);
	if((x+y)%2==0){
		if(x==0&&y==0) printf("0");
		else printf("-1");
	}
	else{
		int count=0;
		long long temp=(x>y)?x:y;
		temp=(temp>fabs(x)+fabs(y))?temp:fabs(x)+fabs(y);
		while(temp!=0){
			count++;
			temp/=2;
		}
		printf("%d",count);
	}
}