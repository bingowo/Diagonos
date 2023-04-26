#include<stdio.h>
void trans(int n, int r){
	char table[]="0123456789ABCDEFGHIJK" ;//table映射表
	int temp;
	if(n != 0){			
		if(n%r < 0)
			temp = n % r - r,trans(n/r+1,r);
		else
			temp = n % r,trans(n/r,r);
		
		printf("%c",table[temp]);
	}
}
int main(){
	int n,r;
	scanf("%d%d",&n,&r);
	
	if(n==0)
		putchar('0');
	else
		trans(n,r);
	printf("\n");
	
	return 0;
}