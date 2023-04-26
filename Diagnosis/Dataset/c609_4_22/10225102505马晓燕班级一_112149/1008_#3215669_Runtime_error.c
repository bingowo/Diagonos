#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *p;
    while (scanf("%s",p) != -1)
    {
        if(strchr(p,'.') == NULL)  //整数
        {
            int val = atoi(p);
            int *pp = &val;
            int len = sizeof(val);
            for(int i=0;i<len;i++)
            {
                printf("%02x ",*((unsigned char*)pp+i));

            }
        }
        else
        {
            double f = atof(p);
            double *pp = &f;
            int len = sizeof(f);
            for(int i=0;i<len;i++)
            {
                printf("%02x ",*((unsigned char*)pp+i));

            }
        }
        printf("\n");

    }
    return 0;
}