#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
    char s[100];
    while(gets(s)) {
        if(strchr(s, '.')) {
            double num = atof(s);
            unsigned char* p = (unsigned char*)(&num);
            for(int i=0; i<8; ++i,++p)
                printf("%02x%s",*p,i<7?" ":"\n");
        }else {
            int num = atoi(s);
            unsigned char* p = (unsigned char*)(&num);
            for(int i=0; i<4; ++i,++p)
                printf("%02x%s",*p,i<3?" ":"\n");
        }
    }
    return 0;
}