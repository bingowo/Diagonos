#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	long long int n,result,i,j,t;
	scanf("%lld",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		result=1;
		for(j=0;j<n;j++){
			result*=2;
		}
		printf("case #%lld:\n%lld\n",i,result);
	}
	return 0;
}