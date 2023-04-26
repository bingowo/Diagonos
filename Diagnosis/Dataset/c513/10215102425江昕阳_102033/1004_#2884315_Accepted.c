#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char *s[20];
    int a;
    double b;
    unsigned char*p;
    while(scanf("%s",s)!=EOF){
    if(strchr(s,'.')!=NULL)
    {
        b=atof(s);
        p=&b;
        for(int i=0; i<8; i++)
        {
            printf("%02x ",*(p+i));
        };
    }
    else
    {
        a=atoi(s);
        p=&a;
        for(int i=0; i<4; i++)
        {
            printf("%02x ",*(p+i));
        };
    };
    printf("\n");
    }
    return 0;
}
