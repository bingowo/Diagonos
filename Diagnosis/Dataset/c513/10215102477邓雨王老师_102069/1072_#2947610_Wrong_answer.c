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
		long long temp=y+x;
		long long temp1=x,temp2=y;
		while(temp!=0){
			count++;
			temp/=2;
		}
		int count1=0,count2=0;
		while(temp1!=0){
			count1++;
			temp1/=2;
		} 
		while(temp2!=0){
			count2++;
			temp2/=2;
		}
		long long max=(count>count1)?count:count1;
		max=(max>count2)?max:count2; 
		printf("%d",max);
	}
}