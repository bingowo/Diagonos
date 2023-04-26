#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,k,m;
	scanf("%d",&n);
	for(k=0;k<n;k++){
		scanf("%d",&m);
		printf("case #%d:\n",k);
		printf("%d\n",n/5+n/25+n/125+n/625);
	}
	return 0;
}