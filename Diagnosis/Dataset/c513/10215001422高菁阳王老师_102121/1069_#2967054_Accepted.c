#include <stdio.h>
#include <stdlib.h>
int cnt=0;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int jud(int n){
	int num=0,s=n;
	while(n>0){
	num=num*10+n%10;
	n/=10;	
	}
	if(num==s) return 1;
	else return -1;
}
int res(int n){
   int num=0,s=n,m;
	while(n>0){
	num=num*10+n%10;
	n/=10;	
	}
	m=num+s;
	cnt++;
	if(jud(m)==1) printf("%d %d",cnt,m);
	else return res(m);
}
int main(int argc, char *argv[]) {
	int n;
	scanf("%d",&n);
	res(n);
	return 0;
}