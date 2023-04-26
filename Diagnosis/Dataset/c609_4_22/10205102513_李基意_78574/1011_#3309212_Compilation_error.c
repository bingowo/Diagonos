#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void convert(char* str, long long int* numerator, long long int*
denominator) {
    *numerator = 0;
    *denominator = 1;
    int i = 0;
    while (str[i] != '\0' && str[i] != '.') {
        if (str[i] == '2') {
            *numerator = (*numerator) * 3 - 1;
       }
        else if (str[i] == '0') {
            *numerator = (*numerator) * 3;
       }
        else {
            *numerator = (*numerator) * 3 + 1;
        i++;
   }
    if (str[i] == '.') {
        i++;
        for (*denominator = 1; str[i] != '\0'; i++) {
            *denominator *= 3;
            if (str[i] == '2') {
                *numerator = (*numerator) * 3 - 1;
            }
            else if (str[i] == '0') {
                *numerator = (*numerator) * 3;
            }
            else {
                *numerator = (*numerator) * 3 + 1;
            }
       }
   }
}

long long int gcd(long long int x, long long int y) {
    if (x % y == 0) return y;
    else return gcd(y, x % y);
}
int main() {
    char str[31];
    scanf("%s", str);
    long long int numerator, denominator;
    convert(str, &numerator, &denominator);
    if (numerator < 0 && denominator > 0) {
        numerator = -numerator;
        printf("-");
   }
    if (denominator == 1) {
        printf("%lld", numerator);
   }
    else if (numerator == 0) {
        printf("0");
   }
    else {
        long long int integer = numerator / denominator;
        numerator %= denominator;
        long long int g = gcd(denominator, numerator);
        numerator/=g;
        denominator/=g;
        if(integer!=0){
            printf("%lld",integer);
        }
        printf("%lld",numerator);
        if(denominator!=1){
            printf("%lld",denominator);
        }
    }
    return 0;
}