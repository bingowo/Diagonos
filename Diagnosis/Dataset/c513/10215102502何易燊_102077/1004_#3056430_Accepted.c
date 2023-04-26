#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[101];
    while (scanf("%s",s)!=EOF)
    {
        if (strchr(s,'.'))
        {
            double num = atof(s);
            unsigned char* ptr = (unsigned char*)&num;
            for (int i=0;i<8;i++) printf("%02x ",*(ptr++));
            printf("\n");
        }
        else
        {
            int num = atoi(s);
            unsigned char* ptr = (unsigned char*)&num;
            for (int i=0;i<4;i++) printf("%02x ",*(ptr++));
            printf("\n");
        }
    }
    return 0;
}