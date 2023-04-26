#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char s[100];
    while(scanf("%s",s)!=EOF){
        unsigned char* b;
        int len=0;
        if(strchr(s,'.')){
            double a = atof(s);
            b = (unsigned char*)(&a);
            len = sizeof(double);

        }
        else{
            int a = atoi(s);
            b = (unsigned char*)(&a);
            len = sizeof(int);
        }
        while(len--){
            printf("%02x",*(b++));
            if(len==0){
                printf(" ");
            }else
                printf("\n");
        }
    }
    return 0;
}
