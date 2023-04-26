#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int f(int n,int m){
	if(n<m) return 0;
	if(n==m) return 1;
	if(n>m) return 2*f(n-1,m)-f(n-1-m,m)+(1<<(n-m-1));
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int m,n,k;
	while(scanf("%d %d",&m,&n)!=EOF){
		if(m==-1&&n==-1) break;
		k=f(n,m);
		printf("%d\n",k);
	}
	return 0;
}