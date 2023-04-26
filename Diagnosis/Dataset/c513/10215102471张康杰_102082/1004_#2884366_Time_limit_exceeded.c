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
        while(*pt)
        {
            printf("%02x",*pt);
            putchar(' ');
        }

    }
    else
    {
        unsigned char* pt;
        pt = &a;
        while(*pt)
        {
            printf("%02x",*pt);
            putchar(' ');
        }
    }
    return 0;
}
