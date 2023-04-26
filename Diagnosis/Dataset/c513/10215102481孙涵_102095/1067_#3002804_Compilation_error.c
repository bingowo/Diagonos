#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int T;
	scanf("%d",&T);
	int i;
	long long int first,second,third, fourth;	
	for (i = 0; i < T; i++){
		first = 0;
		second = 1; 
		third = 1;
		fourth = 2;
		int answer, num;
		scanf("%ld",&num);	
		if (num == 0){
			answer = 0;
		}else if (num == 1 || num == 2){
			answer = 1;
		}else if (num == 3){
			answer = 2;
		}
		int j;
		if (num > 3){
		}		
		for (j = 3; j <= num; j++){
			fourth = first + second + third;
			first = second;
			second = third;
			third = fourth;
			}
		}
		answer = fourth;
		printf("case #%d:\n",i);
		printf("%lld\n",answer);
		}	 
	return 0;
}