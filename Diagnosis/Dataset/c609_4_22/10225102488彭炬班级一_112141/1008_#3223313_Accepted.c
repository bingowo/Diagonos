#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF)
        if(strchr(s,'.')==0)
        {
            int n = atoi(s);
            int l = sizeof(n);
            unsigned char* p = (unsigned char*)&(n);
            while(l--)
                printf("%02x ",*p++);
            printf("\n");
        }
        else
        {
            double n = atof(s);
            int l = sizeof(n);
            unsigned char* p = (unsigned char*)&n;
            while(l--)
                printf("%02x ",*p++);
            printf("\n");
        }
        return 0;
}
