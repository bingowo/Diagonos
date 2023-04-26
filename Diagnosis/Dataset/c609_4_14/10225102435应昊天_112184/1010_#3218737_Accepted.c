#include<stdio.h>
void trans(int n,int r);
char tab[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
	int N,R;
	scanf("%d %d",&N,&R);
	if(N == 0)
		putchar('0');
	else
		trans(N,R);
	return 0;
} 
void trans(int n,int r){
	if(n != 0){
		if(n % r < 0){
			trans(n/r+1,r);
			putchar(tab[n%r-r]);
		}else{
			trans(n/r,r);
			putchar(tab[n%r]);
		}
	}
} 