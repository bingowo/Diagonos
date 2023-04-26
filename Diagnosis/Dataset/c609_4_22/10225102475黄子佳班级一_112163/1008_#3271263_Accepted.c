#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char s[100001];
    double a;
    int b;
    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.')!=NULL)
        {
            a=atof(s);
            int i=sizeof(a);
            unsigned char *p;
            p=(unsigned char*)&a;
            while(i--)
            {
                printf("%02x ",*p++);
            }
            printf("\n");
        }
        else{
            b=atoi(s);
            int i=sizeof(b);
            unsigned char *p;
            p=(unsigned char*)&b;
            while(i--)
            {
                printf("%02x ",*p++);
            }
            printf("\n");
        }
    }
    return 0;
}