#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solveint (int n){
    int size = sizeof(int);
    unsigned char* p = (unsigned char*) &n;
    while (size--)
        printf("%02x ",*p++);
    printf("\n");
} 

void solvedouble (double n){
    int size = sizeof(double);
    unsigned char* p = (unsigned char*) &n;
    while (size--)
        printf("%02x ",*p++);
    printf("\n");
}


int main()
{
    char s[32];
    while (scanf("%s", s) != EOF){
        if (strchr(s,'.') == 0)
            solveint(atoi(s));
        else
            solvedouble(atof(s));
    }
    return 0;
}