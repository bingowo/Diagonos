#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sint(int n)
{
    int len=sizeof(int);
    unsigned char *p=(unsigned char*)&n;
    while(len--)
    printf("%02x ",*p++);
    printf("\n");
}

void sdouble(double n)
{
    int len=sizeof(double);
    unsigned char *p=(unsigned char*)&n;
    while(len--)
    printf("%02x ",*p++);
    printf("\n");
}

int main()
{
    char s[31];
    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.')==0)sint(atoi(s));
        else sdouble(atof(s));
    }
    return 0;
}