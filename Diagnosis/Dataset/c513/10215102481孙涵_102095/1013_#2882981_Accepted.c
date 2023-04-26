#include <stdio.h>

int main(void)
{
    char s[40];
    scanf("%s", s);
    long long int integer = 0, numerator = 0, denominator = 1;
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
        printf("%lld", integer);
    }else if(numerator > 0){
        if(integer < 0){
            integer ++;
            numerator = denominator - numerator;
        }
        if(integer == 0){
            printf("%lld %lld", numerator, denominator);
        }else{
            printf("%lld %lld %lld", integer, numerator, denominator);
        }
    }else if(numerator < 0){
        if(integer > 0){
            integer --;
            numerator = denominator + numerator;			
        }
        if(integer == 0){
            printf("%lld %lld", numerator, denominator);
        }else {
            printf("%lld %lld %lld", integer, numerator, denominator);
        }
    }
    return 0;
}