#include <stdio.h>
#include <stdlib.h>
	char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void inte(int n,int r){
	if(n > 0){
		inte(n / r,r);
		putchar(table[n%r]);
	}
}
int main() {

	int t;
	scanf("%d",&t);
	for(int i = 0,i < t,i++){
		int n,r;
		scanf("%d%d",&n,&r);
		if(n==0){
			putchar("0");
			continue;
		}
		if(n < 0){
			n = -n;
			putchar("-");
		}
		inte(n,r);
		printf("/n");
		
	}
	return 0;
}
