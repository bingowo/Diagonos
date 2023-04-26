#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char s[100001];
    double a;
    int b;
    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.')!=NULL)
        {
            a=atof(s);
            int i=sizeof(double)*2;
            unsigned char *p;
            p=(unsigned char*)&a;
            for(int k=0;k<i;k+=2)
            {
                printf("%02x ",p[k]);
            }
            printf("\n");
        }
        else{
            b=atoi(s);
            int i=sizeof(int)*2;
            unsigned char *p;
            p=(unsigned char*)&b;
            for(int k=0;k<i;k+=2)
            {
                printf("%02x ",p[k]);
            }
            printf("\n");
        }
    }
    return 0;
}