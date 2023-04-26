#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void slvint(int n)
{
    int len=sizeof(n);
    unsigned char*p=(unsigned char*)&n;
    while(len--)
    {
        printf("%02x ",*p++);
    }
    printf("\n");
}

void slvdouble(double n)
{
    int len=sizeof(n);
    unsigned char*p=(unsigned char*)&n;
    while(len--)
    {
        printf("%02x ",*p++);
    }
    printf("\n");
}

int main()
{
    char s[31];
    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.')!=0) slvdouble(atof(s));
        else slvint(atoi(s));
    }
    return 0;
}
