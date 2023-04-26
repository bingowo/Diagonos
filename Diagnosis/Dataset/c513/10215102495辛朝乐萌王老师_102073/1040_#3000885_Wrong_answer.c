#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define LEN 110

void Printtype(char f[],char m[])
{
    if (strcmp(f, "A")==0&&strcmp(m, "A")==0) {
        printf("{A,O}");
    }
    else if(strcmp(f, "A")==0&&strcmp(m, "B")==0){
        printf("{A,AB,B,O}");
    }
    else if(strcmp(f, "B")==0&&strcmp(m, "A")==0){
        printf("{A,AB,B,O}");
    }
    else if(strcmp(f, "A")==0&&strcmp(m, "O")==0){
        printf("{A,O}");
    }
    else if(strcmp(f, "O")==0&&strcmp(m, "A")==0){
        printf("{A,O}");
    }
    else if(strcmp(f, "B")==0&&strcmp(m, "O")==0){
        printf("{B,O}");
    }
    else if(strcmp(f, "O")==0&&strcmp(m, "B")==0){
        printf("{B,O}");
    }
    else if(strcmp(f, "O")==0&&strcmp(m, "O")==0){
        printf("{O}");
    }
    else if(strcmp(f, "AB")==0&&strcmp(m, "AB")==0){
        printf("{A,AB,B}");
    }
    else if(strcmp(f, "AB")==0&&strcmp(m, "A")==0){
        printf("{A,AB,B}");
    }
    else if(strcmp(f, "A")==0&&strcmp(m, "AB")==0){
        printf("{A,AB,B}");
    }
    else if(strcmp(f, "AB")==0&&strcmp(m, "B")==0){
        printf("{A,AB,B}");
    }
    else if(strcmp(f, "B")==0&&strcmp(m, "AB")==0){
        printf("{A,AB,B,O}");
    }
    else if(strcmp(f, "AB")==0&&strcmp(m, "O")==0){
        printf("{A,B}");
    }
    else if(strcmp(f, "O")==0&&strcmp(m, "AB")==0){
        printf("{A,B}");
    }
}

void find(char f[],char k[])
{
    if (strcmp(f, "A")==0&&strcmp(k, "A")==0) {
        printf("{A,AB,B,O}");
    }
    else if(strcmp(f, "A")==0&&strcmp(k, "B")==0){
        printf("{AB,B}");
    }
    else if(strcmp(f, "B")==0&&strcmp(k, "A")==0){
        printf("{A,AB}");
    }
    else if(strcmp(f, "B")==0&&strcmp(k, "B")==0){
        printf("{A,AB,B,O}");
    }
    else if(strcmp(f, "A")==0&&strcmp(k, "O")==0){
        printf("{A,B,O}");
    }
    else if(strcmp(f, "O")==0&&strcmp(k, "A")==0){
        printf("{A,B,O}");
    }
    else if(strcmp(f, "B")==0&&strcmp(k, "O")==0){
        printf("{A,B,O}");
    }
    else if(strcmp(f, "O")==0&&strcmp(k, "B")==0){
        printf("{AB,B}");
    }
    else if(strcmp(f, "O")==0&&strcmp(k, "O")==0){
        printf("{A,B,O}");
    }
    else if(strcmp(f, "AB")==0&&strcmp(k, "AB")==0){
        printf("{A,AB,B}");
    }
    else if(strcmp(f, "AB")==0&&strcmp(k, "A")==0){
        printf("{A,AB,B,O}");
    }
    else if(strcmp(f, "A")==0&&strcmp(k, "AB")==0){
        printf("{A,AB,B,O}");
    }
    else if(strcmp(f, "AB")==0&&strcmp(k, "B")==0){
        printf("{A,AB,B,O}");
    }
    else if(strcmp(f, "B")==0&&strcmp(k, "AB")==0){
        printf("{A,AB,B,O}");
    }
    else if(strcmp(f, "AB")==0&&strcmp(k, "O")==0){
        printf("impossible");
    }
    else if(strcmp(f, "O")==0&&strcmp(k, "AB")==0){
        printf("impossible");
    }
}

int main()
{
    char f[3],m[3],k[3];
    scanf("%s %s %s",f,m,k);
    if (strcmp(k, "?")==0) {
        printf("%s %s ",f,m);
        Printtype(f, m);
    }
    else if(strcmp(m, "?")==0){
        printf("%s ",f);
        find(f, k);
        printf(" %s",k);
    }
    else if(strcmp(f, "?")==0){
        find(m, k);
        printf(" %s %s",m,k);
    }
    return 0;
}
