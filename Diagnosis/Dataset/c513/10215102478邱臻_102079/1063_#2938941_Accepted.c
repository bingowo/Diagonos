#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	long long int x,y,total=0;
	scanf("%lld%lld",&x,&y);   //x长 y宽
	while(x!=0 && y!=0){
		if(x>=y){
			total+=(x/y)*4*y;
			x=x-x/y*y;
		}
		else{
		    total+=(y/x)*4*x;
			y=y-y/x*x;	
		}
	}
	printf("%lld",total);
	return 0;
}