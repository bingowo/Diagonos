#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void trans(int n,int r);
char tab[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
	int T;
	scanf("%d",&T);
	int n,r;
	for(int i = 0;i < T;i++){
		scanf("%d %d",&n,&r);
		if(n < 0){
			putchar('-');
			n = -n;	
		}
		if(n == 0)
			putchar('0'); 
		else
			trans(n,r);
		printf("\n");
	}
	return 0;
}
void trans(int n,int r){
	if(n > 0){
		trans(n/r,r);
		putchar(tab[n%r]);
	} 
}