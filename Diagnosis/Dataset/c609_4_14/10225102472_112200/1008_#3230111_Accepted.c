#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100] = "\0";

    while(scanf("%s", s) != EOF)
    {
        if(strchr(s, '.') == 0)
        {
            int ss = atoi(s);
            int len = sizeof(ss);
            unsigned char *p = (unsigned char *)&ss;
            while(len--)
            {
                printf("%02x ", *(p++));
            }
            printf("\n");
        }

        else
        {
            double ss = atof(s);
            int len = sizeof(ss);
            unsigned char *p = (unsigned char *)&ss;
            while(len--)
            {
                printf("%02x ", *(p++));
            }
            printf("\n");
        }
    }

    return 0;
}