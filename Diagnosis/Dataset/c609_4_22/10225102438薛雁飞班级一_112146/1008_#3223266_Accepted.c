#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[33];
    while (scanf("%s",s)!=EOF){
        int a;
        double b;
        unsigned char *p;
        if(strchr(s,'.'))
        {
            b=atof(s);
            p=(unsigned char*)&b;
            for(int i=0;i<sizeof(double);i++){
                printf("%02x ",*p++);
            }
            printf("\n");
        }
        else
        {
            a=atoi(s);
            p=(unsigned char*)&a;
            for(int i=0;i<sizeof(int);i++){
                printf("%02x ",*p++);
            }
            printf("\n");
        }
    }
    return 0;
}
