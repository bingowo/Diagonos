#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int T;
	scanf("%d",&T);
	int i;
	for (i = 0; i < T; i++){
		int n;
		scanf("%d",&n);
		printf("case #%d:\n",i);
		printf("%d\n", ans(n));
	}
	return 0;
}

int ans(int n){
	if (n == 1){
		return 1;
	}else if( n == 2 ){
		return 2;
	}else if (n == 3){
		return 4;
	}else if (n == 4){
		return 8;
	}
	return ans(n-1) + ans(n-2) + ans(n-3) + ans(n-4);
}