#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str;
    while(scanf("%s",str) != EOF)
    {

        if(strchr(str,'.')) {double x = atof(str); int bite = sizeof(x);double *p = &bite;}
        else {int x = atoi(str); int bite = sizeof(x);int *p = &bite;}
        unsigned char*p;
        printf("%02x", (unsigned char*)p);
    }
}

