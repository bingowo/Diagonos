#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char s[100];
    while(scanf("%s",s)!=EOF){
        unsigned char* b;
        int len;
        if(strchr(s,'.')){
            double a = atof(s);
            double* pa = &a;
            b = (unsigned char*)pa;
            len = sizeof(double);

        }
        else{
            int a = atoi(s);
            int* pa = &a;
            b = (unsigned char*)pa;
            len = sizeof(int);
        }
        for(int i= 0;i<len;i++){
            printf("%02x",*(b++));
            if(i!=len-1){
                printf(" ");
            }else
                printf("\n");
        }
    }
    return 0;
}
