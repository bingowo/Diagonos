#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[40];
int main(){
	scanf("%s", &str);
	int i, len = strlen(str), point = 0, num = 0, integer = 0, numerator = 0, denominator = 1 , sign = 1, mult = 1;
	point = len;
	for(i = 0; i < len; ++i)	if(str[i] == '.')	point = i;
	for(i = point - 1; i >= 0; --i){
		if(str[i] == '2')	integer += -1 * mult; 
		else	integer += (str[i] - '0') * mult;
		mult *= 3;
	}
	for(i = len - 1; i > point; --i){
		if(str[i] == '2')	numerator += -denominator;
		else	numerator += (str[i] - '0') * denominator;
		denominator *= 3;
	}
	if(integer > 0 && numerator > 0)	printf("%d %d %d", integer, numerator, denominator);
	else if(integer < 0 && numerator < 0)	printf("%d %d %d", integer, -numerator, denominator);
	else if(integer > 0 && numerator < 0)	printf("%d %d %d", integer - 1, denominator + numerator, denominator);
	else if(integer < 0 && numerator > 0)	printf("%d %d %d", integer + 1, denominator - numerator, denominator);
	else if(numerator == 0)	printf("0");
	else if(integer == 0)	printf("%d %d", numerator, denominator);
	return 0;
}