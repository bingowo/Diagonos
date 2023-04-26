#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[64];
    int vali;
    double valf;
    while (scanf("%s", s) == 1)
    {
        char *p = strstr(s, "."); // <=> char *p = strchr(s, '.');
        if (p != NULL)
        {
            valf = atof(s);
            char *p = (char *)(&valf);
            for (int i = 0; i < sizeof(double) - 1; ++i)
            {
                printf("%02x ", 0xff & p[i]);
            }
            printf("%02x\n", 0xff & p[sizeof(double) - 1]);
        }
        else
        {
            vali = atoi(s);
            char *p = (char *)(&vali);
            for (int i = 0; i < sizeof(int) - 1; ++i)
            {
                printf("%02x ", 0xff & p[i]);
            }
            printf("%02x\n", 0xff & p[sizeof(int) - 1]);
        }
    }
    return 0;
}