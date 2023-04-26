#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char s[31];
    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.')==0)
        {
            int n=atoi(s);
            int a=sizeof(n);
            unsigned char *p=(unsigned char *)&n;
            while(a--)
                printf("%02x ",*p++);
            printf("\n");
        }
        else
        {
            double n=atof(s);
            int a=sizeof(n);
            unsigned char *p=(unsigned char *)&n;
            while(a--)
                printf("%02x ",*p++);
            printf("\n");
        }
    }
    return 0;
}
