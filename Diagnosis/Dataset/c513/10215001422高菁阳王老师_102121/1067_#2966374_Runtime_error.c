#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long T(long long n){
	long long arr[n+1],i;
	arr[0]=0;
	arr[1]=1;
	arr[2]=1;
	for(i=3;i<=n;i++){
		arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
	}return arr[n];
}

int main(int argc, char *argv[]) {
	int n,k,m,l;
	scanf("%lld",&n);
	for(k=0;k<n;k++){
		scanf("%lld",&m);
		printf("case #%lld:\n",k);
		l=T(m);
		printf("%lld\n",l);
	}
	return 0;
}