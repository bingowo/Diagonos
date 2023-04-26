#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char n[32];
    while ((scanf("%s",n)) != EOF)
    {
        int i,flag = 0;
        for (i = 0; i < strlen(n); i++)
        {
            if (n[i] == '.') flag = 1;
        }
        if (flag == 0)//说明是整数
        {
            int x = atoi(n);
            unsigned char *p = (unsigned char *)(&x);
            for (int i = 0; i < sizeof(int);i++)
            {
                printf("%02x ",*(p++));
            }
            printf("\n");
        }
        else//说明是浮点数
        {
            double x = atof(n);
            unsigned char *p = (unsigned char *)(&x);
            for (int i = 0; i < sizeof(double);i++)
            {
                printf("%02x ",*(p++));
            }
            printf("\n");
        }
    }
}
