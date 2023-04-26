#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[31];
    char c='.';
    while (scanf("%s",s)!=EOF)
    {
        if(strchr(s,c)==0)
        {
            int a=atoi(s);
            int m=sizeof (int );
            unsigned char *p=(unsigned char *)&a;
            for (int i=0; i<m; i++)
            {
                printf("%02x ",*p++);
            }
        }
        else
        {
            double b=atof(s);
            int n=sizeof(double );
            unsigned char *q=(unsigned char *)&b;
            for (int j=0; j<n; j++)
            {
                printf("%02x ",*q++);
            }
        }
        printf("\n");
    }

    return 0;
}
