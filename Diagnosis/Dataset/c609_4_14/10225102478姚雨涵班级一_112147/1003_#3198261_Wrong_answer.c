#include <stdio.h>
#include <stdlib.h>
	char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void inte(int n){
	if(n > 0){
		inte(n / 2333);
		printf("%d ",n%2333);
	}
}
int main() {

	int t,i=0;
	scanf("%d",&t);
	while(i < t){
		i++;
		int n;
		scanf("%d",&n);
		if(n==0){
			printf("0");
			continue;
		}
		if(n < 0){
			n = -n;
			printf("-");
		}
		inte(n);
		printf("\n");
		
	}
	return 0;
}
