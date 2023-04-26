#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	long long int x,y,total=0;
	scanf("%lld%lld",&x,&y);   //x长 y宽
	while(x>=y && y!=0){
		total+=y*4;
		x=x-y;
	}
	while(x<=y & x!=0){
		total+=x*4;
		y=y-x;
	} 
	printf("%lld",total);
	return 0;
}