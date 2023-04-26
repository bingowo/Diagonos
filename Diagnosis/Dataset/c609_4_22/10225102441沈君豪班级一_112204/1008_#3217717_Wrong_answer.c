#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char s[100];
    int x=0;
    unsigned char* t;
    while((scanf("%s",s))!=EOF){
        if((strchr(s,'.'))==NULL){
            int a = atoi(s);
            x = sizeof(a);
            int* b=&a;
            t=(unsigned char*)b;
        }else{
            double a = atof(s);
            x = sizeof(a);
            double* c=&a;
            t=(unsigned char*)c;}
        for(int i=0;i<x;i++){
            printf("%02x ",*t++);
        }
        printf("\n");
    }
    return 0;
}
