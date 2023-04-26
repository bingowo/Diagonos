#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct dot{
	long long int x,y;
};
void move(long long int k,long long int x,long long int y){
	long long int d=pow(2,k-1);
	if(k){
		if(llabs(x)>llabs(y)){
			if(x>0){
				k-=1;x-=d;
				move(k,x,y);printf("E");
			}
			else {
				k-=1;x+=d;
				move(k,x,y);printf("W");
			}
		} //水平方向走 
		else {
			if(y>0){
				k-=1;y-=d;
				move(k,x,y);printf("N");
			}
			else {
				k-=1;y+=d;
				move(k,x,y);printf("S");
			}
		}
	}
}
int main(int argc, char *argv[]) {
	long long int n,count,i,j,k;
	unsigned long long int r;
	struct dot num;
	scanf("%lld%lld",&num.x,&num.y);
    r=llabs(num.x)+llabs(num.y);
    count=0;
    if(r==0)count=0;
    else if(r%2==0)count=-1;  //不能到达 
	else {
		k=0;
		while(pow(2,k)-1<r || pow(2,k-1)-1>=r)k++;
		count+=k;
	}
	if(count==-1 || count==0)printf("%lld",count);
	else {
		printf("%lld\n",count);
		move(count,num.x,num.y);
	}
	return 0;
}