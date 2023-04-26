#include<stdio.h>
#include<math.h>
int main(){
	long long x,y;
	scanf("%lld %lld",&x,&y);
	if(x<0) x*=-1;
	if(y<0) y*=-1;
	long long sum=x+y;
	if((x+y)%2==0) printf("-1");
	else{
		int count=0;
		while(sum){
			sum/=2;
			count++;
		}
		printf("%d",count);
	}
} 