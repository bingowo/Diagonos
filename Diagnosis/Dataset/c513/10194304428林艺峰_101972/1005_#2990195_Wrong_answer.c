#include<stdio.h>
#include<math.h>
int main(){
	char eight[20];
	double sum;
	int i;
	while( scanf("%s",eight) != EOF ){
		sum = 0.0;
		for(i = 2; eight[i] != '\0'; i++){
			sum += (eight[i] - '0') * pow(0.125 , i-1);
		}
		printf("%s [8] = %0.45g [10]\n", eight, sum);
	}
 
	return 0;
}