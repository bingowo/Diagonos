#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char s[100] = {0};
    while((scanf("%s",s)) != EOF)
    {
        int flag = 0;
        for(int i = 0;i < strlen(s);i++)
        {
            if(s[i] == '.')
                flag = 1;
        }
        if(flag)
        {
            double n = atof(s);
            int p = sizeof(n);
            char *e = (unsigned char *)&n;
            while(p--)
                printf("%02x ",*e++);
            printf("\n");
        }
        else
        {
            int n = atoi(s);
            int p = sizeof(n);
            unsigned char *e = (unsigned char *)&n;
            while(p--)
                printf("%02x ",*e++);
            printf("\n");
        }
    }

    return 0;
}