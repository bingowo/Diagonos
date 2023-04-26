#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len;
char* p;

char* Fun(char* s){
    static double f;
    static int d;
    if(strchr(s,'.')){
        f=atof(s);
        len=sizeof(f);
        return &f;
    }
    else{
        d=atoi(s);
        len=sizeof(d);
        return &d;
    }
}

int main(){
    char s[20];
    while(scanf("%s",s)!=EOF){
        p=Fun(s);
        for(int i=0;i<len;i++)
            printf("%02x ",*(p+i)&255);
        printf("\n");
    }
    return 0;
}
