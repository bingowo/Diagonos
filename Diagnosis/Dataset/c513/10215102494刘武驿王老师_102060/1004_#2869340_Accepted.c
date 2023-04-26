#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[100];
    while(scanf("%s",str)!=EOF)
    {
        int mark=0;
        for(int i=0;i<strlen(str);i++)
        {
            if(str[i]=='.') mark=1;
        }
        if(mark==0)
        {
            int n=atoi(str);
            int p=sizeof(n);
            unsigned char*e=(unsigned char *)&n;
            while(p--)
            {
                    printf("%02x ",*e++);
            }
                  printf("\n");
        }
        else
        {
            double n=atof(str);
            int p=sizeof(n);
            unsigned char*e=(unsigned char *)&n;
            while(p--)
                {
                    printf("%02x ",*e++);
                }
                printf("\n");
        }
    }
}