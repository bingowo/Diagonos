#include<stdio.h>
int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	int sum=0;
	int gs;
	if(x%y==0){
		gs=x/y;
		sum=4*x*(x/y);
	}
	printf("%d",sum);
}