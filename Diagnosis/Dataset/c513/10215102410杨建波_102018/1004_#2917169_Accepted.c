#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void int_(int a);
void double_(double b);


int main(){
    char a[31];
    while(scanf("%s",a)!=EOF){
        if(strchr(a, '.')==0)
        int_(atoi(a));
        else
        double_(atof(a));
    }
}

void int_(int a){
    int c = sizeof(a);
    unsigned char *p = (unsigned char*)&a;
    while(c--)
    printf("%02x ",*p++);
    printf("\n");
}

void double_(double a){
    int c = sizeof(a);
    unsigned char *p = (unsigned char*)&a;
    while(c--)
    printf("%02x ",*p++);
    printf("\n");
}

