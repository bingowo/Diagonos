#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char s[100];
    while(scanf("%s",s) != EOF)
    {
        if(strchr(s,'.') != NULL)
        {
            double f = atof(s);
            int c = sizeof(f);
            unsigned char * p = (unsigned char *) (&f);
            while(c--)
            {
                printf("%02x ",*p++);
            }
            printf("\n");
        }
        else
        {
            int g = atoi(s);
            int d = sizeof(g);
            unsigned char * q = (unsigned char *) (&g);
            while(d--)
            {

                printf("%02x ",*q++);
            }
            printf("\n");
        }
    }
}