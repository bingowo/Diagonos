#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char s[1000];
    int x;
    unsigned char* t;
    int a;
    double b;
    while(scanf("%s",&s)!=EOF){
        if(strchr(s,'.')==0){
            a=atoi(s);
            x=sizeof(a);
            t=(unsigned char*)&a;
        }
        else{
            b=atof(s);
            x=sizeof(b);
            t=(unsigned char*)&b;
        }
        for(int i=0;i<x;i++)
            printf("%02x ",*t++);
        printf("\n");
    }
    return 0;
}