#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	long long int n,k,m,s[100];
	for(i=5;i<51;i++){
	
	s[1]=1;s[2]=2;s[3]=4;s[4]=8;
	s[i]=s[i-1]+s[i-2]+s[i-3]+s[i-4];
}
	scanf("%lld",&n);
	for(int i=0;i<k;i++){
		scanf("%lld",&m);
		printf("case #%d:\n",k);
		printf("%d\n",s[m]);
	}
	return 0;
}