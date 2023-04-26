#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char s[100];
    while(scanf("%s",s)!=EOF){
        if(strchr(s,'.')){
            double a = atof(s);
            unsigned char* b = (unsigned char*)(&a);
            int len = sizeof(double);
            while(len--){
                printf("%02x%c",*(b++),len==0?'\n':' ');
            }

        }
        else{
            int a = atoi(s);
            unsigned char* b = (unsigned char*)(&a);
            int len = sizeof(int);
            while(len--){
                printf("%02x%c",*(b++),len==0?'\n':' ');
            }
        }

    }
    return 0;
}
