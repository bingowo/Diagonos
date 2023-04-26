#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[30];
    int a,i;
    double b;
    while(gets(s))
    {
        if( strchr(s,'.')== 0)
        {
            a = atoi(s);
            i = sizeof (a);
            unsigned char* p=(unsigned char*)&a;
            while(i -- )
                printf("%02x ",*p++);
            printf("\n");
        }
        else
        {
            b = atof(s);
            i = sizeof (b);
            unsigned char* p=(unsigned char*)&b;
            while(i -- )
                printf("%02x ",*p++);
            printf("\n");
        }
    }
    
    return 0;
}
