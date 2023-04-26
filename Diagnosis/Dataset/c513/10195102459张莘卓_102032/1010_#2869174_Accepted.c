#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binary(int n) {
    int code[10];
    for(int i=9; i>=0; --i) {
        code[i] = n % 2;
        n /= 2;
    }
    for(int i=0; i<10; ++i) printf("%d",code[i]);
}

void tranform(char* s) {
    int num = 0, k,code[10];
    for(k=0; k<3 && s[k]; ++k)
        num = num * 10 + s[k] - '0';
    int cnt = k * 3 + 1;
    for(k=cnt-1; k>=0; --k) {
        code[k] = num % 2;
        num /= 2;
    }
    for(k=0; k<cnt; ++k) printf("%d",code[k]);
}

int main()
{
    char n[501];
    scanf("%s",n);
    printf("0001");
    binary(strlen(n));
    for(int k=0; k<strlen(n); k+=3) {
        tranform(&n[k]);
    }
    printf("\n");
}
