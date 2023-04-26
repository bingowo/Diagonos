#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	long long int f[50]={0};
	int n,i;
	scanf("%d",&n);
	f[0]=1;
	f[1]=1;
	f[2]=2;
	f[3]=4; 
	for(i=4;i<=n;i++){
		f[i]=f[i-1]+f[i-2]+f[i-3]+f[i-4];
	}
	printf("%lld",f[n]);
	return 0;
}