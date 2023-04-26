#include <stdio.h>

int main(void)
{
	char s[40];
	scanf("%s", s);
	int integer = 0, numerator = 0, denominator = 1;
	char *p = s;
	while(*p != '.' && *p){
		integer = integer * 3;
		if(*p == '1'){
			integer += 1;
		}else if(*p == '2'){
			integer -= 1;
		}
		p ++;	
	}
	if(*p){
		p ++;
	}
	while(*p){
		denominator *= 3;
		numerator *= 3;
		if(*p == '1'){
			numerator += 1;
		}else if(*p == '2'){
			numerator -= 1;
		}
		p ++;
	}
	if(numerator == 0){
		printf("%d", integer);
	}else if(numerator > 0){
		if(integer < 0){
			integer ++;
			numerator = denominator - numerator;
		}
		if(integer == 0){
			printf("%d %d", numerator, denominator);
		}else{
			printf("%d %d %d", integer, numerator, denominator);
		}
	}else if(numerator < 0){
		if(integer > 0){
			integer --;
			numerator = denominator + numerator;			
		}
		if(integer == 0){
			printf("%d %d", numerator, denominator);
		}else {
			printf("%d %d %d", integer, numerator, denominator);
		}
	}
	return 0;
}