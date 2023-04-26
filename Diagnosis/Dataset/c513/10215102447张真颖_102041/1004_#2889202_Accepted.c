#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[17];
    while(scanf("%s",s)==1)
   {char *ret=strchr(s,'.');
    if(ret==0)
    {
        int i=atof(s);
        int m=0;
        for(unsigned char* j=(unsigned char*)&i;m<sizeof(i);j++,m++)
            printf("%02x%c",*j,m!=sizeof(i)-1?' ':'\n');
    }
    else
    {
        double f=atof(s);
        int m=0;
        for(unsigned char* j=(unsigned char*)&f;m<sizeof(f);j++,m++)
            printf("%02x%c",*j,m!=sizeof(f)-1?' ':'\n');
    }
    }
    return 0;
}