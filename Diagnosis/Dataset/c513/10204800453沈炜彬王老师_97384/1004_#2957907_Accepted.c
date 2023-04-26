#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(char *pnum);

int main()
{
    char num[20] = {'\0'};
    int num_int;
    double num_double;
    while (~scanf("%s",num))
    {
        if (find(num))
        {
            num_int = atoi(num);
            void *pnum = &num_int;
            for (int i=0; i<4; i++)
            {
                printf("%02x ",*((unsigned char*)pnum +i));
            }
            printf("\n");
        }
        else
        {
            num_double = atof(num);
            void *pnum = &num_double;
            for (int i=0; i<8; i++)
            {
                printf("%02x ",*((unsigned char*)pnum +i));
            }
            printf("\n");
        }
        char num[20] = {'\0'};
    }
    
    return 0;
}

int
find(char *pnum)
{
    for (int i=0; i<strlen(pnum); i++)
    {
        if (pnum[i] == '.')
        {
            return 0;
        }
    }
    return 1;
}