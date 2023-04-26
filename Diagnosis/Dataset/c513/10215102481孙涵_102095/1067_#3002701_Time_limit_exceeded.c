#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int tribonacci(int a);

int main(int argc, char *argv[]) {
	int T;
	scanf("%d",&T);
	int i;
	for (i = 0; i < T; i++){
		int answer, num;
		scanf("%d",&num);
		answer = tribonacci(num);
		printf("case #%d:\n",i);
		printf("%d",answer);
	} 
	return 0;
}

int tribonacci(int a){
	if (a == 0){
		return 0;
	}else if (a == 1){
		return 1;
	}else{
		return tribonacci(a-1) + tribonacci(a-2);
	}
}