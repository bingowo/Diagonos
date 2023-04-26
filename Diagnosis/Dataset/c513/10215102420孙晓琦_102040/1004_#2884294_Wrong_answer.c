#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[31];
    char c='.';
    scanf("%s",s);
    if(strchr(s,c)==0)
    {
        int a=atoi(s);
        int m=sizeof (int );
        char *p=(unsigned char *)&a;
        for (int i=0;i<m;i++)
        {
            printf("%02x ",*p++);
        }
    }
    else
    {
        double b=atof(s);
        int n=sizeof(double );
        char *q=(unsigned char *)&b;
        for (int j=0;j<n;j++)
        {
            printf("%02x ",*q++);
        }
    }
    return 0;
}
