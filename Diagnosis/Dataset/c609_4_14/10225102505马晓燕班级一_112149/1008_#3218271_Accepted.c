#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char p[1000];
    while (scanf("%s",p) != -1)
    {
        if(strchr(p,'.') == NULL)  //整数
        {
            int val = atoi(p);
            int *pp = &val;
            for(int i=0;i<sizeof(val);i++)
            {
                printf("%02x ",*((unsigned char*)pp+i));
            }
        }
        else                    //double型
        {
            double f = atof(p);
            double *pp = &f;
            for(int i=0;i<sizeof(f);i++)
            {
                printf("%02x ",*((unsigned char*)pp+i));
            }
        }
        printf("\n");

    }
    return 0;
}
