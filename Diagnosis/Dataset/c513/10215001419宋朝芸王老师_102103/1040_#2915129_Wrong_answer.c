#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getblood(char *a){
    //a 1, b 2, ab 3, o 4;
    int len = strlen(a);
    if(len == 2) return 3;
    if(*a == 'A' || *a == 'a') return 1;
    if(*a == 'B' || *a == 'b') return 2;
    if(*a == 'O' || *a == 'o') return 4;
    return 0;
}

void getchi(char *a1, char *a2, char *a3){ //a3 is unknown
    int f = getblood(a1)*10 + getblood(a2);

    if(f == 11 || f == 14 || f == 41) {strcpy(a3,"{A,O}");return 0;}
    else if(f == 22 || f == 24 || f == 42) {strcpy(a3,"{B,O}");return 0;}
    else if(f == 44) {strcpy(a3,"{O}");return 0;}
    else if(f == 34 || f == 43) {strcpy(a3,"{A,B}");return 0;}
    else if(f == 12 || f == 21) {strcpy(a3,"{A,AB,B,O}");return 0;}
    //if(f == 33){
    else strcpy(a3,"{A,AB,B}");
    //return 0;}
}

void getpar(char *a1, char *a2, char *a3){   //a1 is unknown
    int f = getblood(a2)*10 + getblood(a3);

    if(f == 44) {strcpy(a1,"{O}");return 0;}
    else if(f == 13 || f == 42) {strcpy(a1,"{AB,B}");return 0;}
    else if(f == 23 || f == 41) {strcpy(a1,"{A,AB}");return 0;}
    else if(f == 33) {strcpy(a1,"{A,AB,B}");return 0;}
    else if(f == 11) {strcpy(a1,"{A,AB,O}");return 0;}
    else if(f == 31) {strcpy(a1,"{A,O}");return 0;}
    else if(f == 22) {strcpy(a1,"{AB,B,O}");return 0;}
    else if(f == 32) {strcpy(a1,"{B,O}");return 0;}

    else strcpy(a1,"impossible");
}

int main()
{
    char f[11] = {'\0'}, m[11] = {'\0'}, c[11] = {'\0'};
    scanf("%s%s%s",f,m,c);

    if(c[0] == '?') getchi(f,m,c);
    else if(f[0] == '?') getpar(f,m,c);
    else if(m[0] == '?') getpar(m,f,c);

    printf("%s %s %s",f,m,c);

    return 0;
}
