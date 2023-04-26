#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//a为第一次上车人数，x为从x站开出时人数，
int fun(int a,int x,int t){
	int sum;
	if(x==1) sum=a;
	if(x==2) sum=a;
	if(x==3) sum=a+t;
	if(x=4) sum=a*2+t;
	if(x>4) sum=fun(a,x-1,t)-fun(a,x-3,t);
	return sum;
}
int main(int argc, char *argv[]) {
	int a,n,m,x,t,res=0,flag=0;//t为第二次上车人数
	scanf("%d %d %d %d",&a,&n,&m,&x);
	for(t=0;t<=10000;t++){
		if(fun(a,n-1,t)==m){
			flag=1;
			break;
		}
	}
	if(t>=0&&t<=10000){
		res=fun(a,x,t);
	}
	printf("%d",res);
	return 0;
}