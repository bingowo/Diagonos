#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int a,flag = 0;
    double b;
    char input[30];
    scanf("%s",&input);
    if(strchr(input,'.') != NULL)
    {
        b = atof(input);
        flag = 1;
    }

    else
        a = atoi(input);
    if(flag)
    {
        unsigned char* pt;
        pt = &b;
        int len = sizeof(b);
        for(int j = 0;j < len;j++)
        {
            printf("%02x",*pt);
            pt++;
            putchar(' ');
        }

    }
    else
    {
        unsigned char* pt;
        pt = &a;
        int len = sizeof(a);
        for(int j = 0;j < len;j++)
        {
            printf("%02x",*pt);
            pt++;
            putchar(' ');
        }
    }
    return 0;
}
