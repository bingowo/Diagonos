#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxline 50

void solveint(int n){
    int c=sizeof(int);
    unsigned char *p=(unsigned char*)&n;
    while(c--)printf("%02x ",*p++);
}

void solvedouble(double n){
    int c=sizeof(double);
    unsigned char *p=(unsigned char*)&n;
    while(c--)printf("%02x ",*p++);
    
}

int main(){
    char s[maxline];
    while(scanf("%s",s)!=EOF){
        if(strchr(s,'.'))solvedouble(atof(s));
        else solveint(atoi(s));
        printf("\n");
        
    }
    
    return 0;
}
