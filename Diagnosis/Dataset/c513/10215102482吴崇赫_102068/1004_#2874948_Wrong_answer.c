#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void solveint(int n){
    int len=sizeof(n);
    unsigned char* p=(unsigned char*)&n;
    while(len--)printf("%02x",*p++);
    printf("\n");
}
void solvedouble(double n){
    int len=sizeof(n);
    unsigned char* p=(unsigned char*)&n;
    while(len--)printf("%02x",*p++);
    printf("\n");
}

int main(){
    char s[32]={'\0'};
    while(scanf("%s",s)!=EOF){
        if(strchr(s,'.')==0)solveint(atoi(s));
        else solvedouble(atof(s));
    }
    return 0;
}