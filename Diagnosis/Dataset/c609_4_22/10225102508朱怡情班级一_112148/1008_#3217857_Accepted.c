#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF){
        if(strchr(s,'.')==0){
            int n1=atoi(s);
            unsigned char *p=(unsigned char*)&n1;
            int len=sizeof(n1);
            while(len--){
                printf("%02x ",*p++);
            }
        }
        else{
            double n2=atof(s);
            unsigned char *p=(unsigned char*)&n2;
            int len=sizeof(n2);
            while(len--){
                printf("%02x ",*p++);
            }
        }
        printf("\n");
    }
    return 0;
}
