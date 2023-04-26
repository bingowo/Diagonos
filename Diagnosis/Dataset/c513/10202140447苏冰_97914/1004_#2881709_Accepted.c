#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char s[50];
    while(scanf("%s",s)!=EOF)
    {
        int m=0;
        unsigned char* p=(unsigned char*)(&m);
        double e;int t;
        if(strchr(s,'.'))
        {
            e=atof(s);
            m=sizeof(e);
            p=(unsigned char*)(&e);
        }
        else
        {
            t=atoi(s);
            m=sizeof(t);
            p=(unsigned char*)(&t);
        }
        while(m>0)
        {
            printf("%02x ",*p);
            p++;m--;
        }
        printf("\n");
    }
    return 0;
}

