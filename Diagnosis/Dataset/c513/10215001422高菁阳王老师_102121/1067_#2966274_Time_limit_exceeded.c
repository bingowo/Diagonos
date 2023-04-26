#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long int T(long long int n){
	if(n==0) return 0;
	if(n==1) return 1;
	if(n==2) return 1;
	if(n==3) return 2;
	if(n>3) return T(n-1)+T(n-2)+T(n-3);
}
int main(int argc, char *argv[]) {
	long long int n,k,m,l;
	scanf("%lld",&n);
	for(k=0;k<n;k++){
		scanf("%lld",&m);
		printf("case #%lld:\n",k);
		l=T(m);
		printf("%lld\n",l);
	}
	return 0;
}