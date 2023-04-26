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
        if(strchr(s,',')!=NULL)
        {
            a=atof(s);
            int i=sizeof(double);
            unsigned char *p;
            p=(unsigned char*)&a;
            for(int k=0;k<i;k++)
            {
                printf("%02x",p+2k);
            }
        }
        else{
            b=atoi(s);
            int i=sizeof(int);
            unsigned char *p;
            p=(unsigned char*)&b;
            for(int k=0;k<i;k++)
            {
                printf("%02x ",p+2k);
            }
        }
    }
    return 0;
}
