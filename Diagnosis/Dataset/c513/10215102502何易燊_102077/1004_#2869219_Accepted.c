#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
    char s[100];
    while (scanf("%s",s)!=EOF)
    {
        if (!strchr(s,'.'))
        {
            int n = atoi(s);
            unsigned char* p = (unsigned char*)(&n);
            for (int i=0;i<sizeof(int);i++) printf("%02x ",*(p++));
            printf("\n");
        }
        else
        {
            double n = atof(s);
            unsigned char* p = (unsigned char*)(&n);
            for (int i=0;i<sizeof(double);i++) printf("%02x ",*(p++));
            printf("\n");
        }
    }
    return 0;
}