#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char s[100];
    unsigned char *c;
    double m, *m1;
    int n,*n1,size;
    while(scanf("%s",s) != EOF)
    {
        if(strchr(s,'.')){m = atof(s);m1 = &m;c = (unsigned char*)m1;size = 8;}
        else{n = atoi(s);n1 = &n;c = (unsigned char*)n1;size = 4;}
        while(size-->0)
        {
            printf("%02x ",*c);
            c++;
        }
        printf("\n");
    }
    return 0;
    }
    
