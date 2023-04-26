#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int tribonacci(int a);

int main(int argc, char *argv[]) {
	int T;
	scanf("%d",&T);
	int i;
	for (i = 0; i < T; i++){
		unsigned int answer, num;
		scanf("%ld",&num);
		answer = tribonacci(num);
		printf("case #%d:\n",i);
		printf("%ld\n",answer);
	} 
	return 0;
}

int tribonacci(int a){
	int first,second,third, fourth;
	first = 0;
	second = 1; 
	third = 1;
	fourth = 2;
	if (a == 0){
		return 0;
	}else if (a == 1 || a == 2){
		return 1;
	}else if (a == 3){
		return 2;
	}
	int i;
	for (i = 3; i < a; i++){
		fourth = first + second + third;
		first = second;
		second = third;
		third = fourth;
	}
	return fourth;
}