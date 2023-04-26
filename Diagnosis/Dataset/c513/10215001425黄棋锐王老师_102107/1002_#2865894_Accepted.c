#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long tran(char* p){
	char*q =p;
	int i,d=0,n=1;
	long long sum=0;
	int a[130];
	for(i=0;i<130;i++) a[i]=-1;
	a[*p]=1;//abcd代表不同位置 ,相同位置只需要赋值一次 
	while(*++p){
		if(a[*p]==-1){
			a[*p]=d;
			d=d?d+1:2;
			n++;//赋值几次几进制 
		} 
	}
	if(n<2) n=2;
	p=q;
	while(*p){
		sum=sum*n+a[*p++];//字符串最后为'\0'，值为0 
	}
	return sum;
}
int main(int argc, char *argv[]) {
	int T,i; 
	char s[100];
	scanf("%d\n",&T);
	for(i=0;i<T;i++){
		scanf("%s",s);//后自动加了'\0'
		printf("case #%d:\n",i);
		printf("%lld\n",tran(s));
	}
	
	return 0;
}
