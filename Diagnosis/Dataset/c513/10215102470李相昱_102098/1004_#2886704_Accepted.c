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
            while(len--){
                printf("%02x%c",*(b++),len==0?'\n':' ');
            }

        }
        else{
            int a = atoi(s);
            b = (unsigned char*)(&a);
            len = sizeof(int);
            while(len--){
                printf("%02x%c",*(b++),len==0?'\n':' ');
            }
        }

    }
    return 0;
}
