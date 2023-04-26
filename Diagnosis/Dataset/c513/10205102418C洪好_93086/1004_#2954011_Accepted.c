#include <stdio.h>
#include <string.h>
#include <stdlib.h>

union Buf {
    int i;
    double d;
    unsigned char c[8];
};

int main()
{
    char s[50];
    while(scanf("%s",s)!=EOF)
    {
        union Buf u;
        int m = 0; 
        double e;
        if(strchr(s,'.')==0)
        {
            u.i = atoi(s);
            m = 4;
        }
        else
        {
            u.d = atof(s);
            m = 8;
        }
        for(int i = 0; i < m; ++i)
        {
            printf("%02x",u.c[i]);
            if(i != m - 1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}