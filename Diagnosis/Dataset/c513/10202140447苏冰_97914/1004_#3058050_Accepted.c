#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int main()
{
    char s[50];
    int i=0;
    double d=0;
    int m=0;
    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.'))
        {
            d=atof(s);
            unsigned char* p=(unsigned char*)&d;
            m=sizeof(d);
            while(m)
            {
                printf("%02x ",*p);
                m--;
                p++;
            }
        }
        else
        {
            i=atoi(s);
            unsigned char* p=(unsigned char*)&i;
            m=sizeof(i);
            while(m)
            {
                printf("%02x ",*p);
                m--;
                p++;
            }
        }
        printf("\n");
    }
    return 0;
}

