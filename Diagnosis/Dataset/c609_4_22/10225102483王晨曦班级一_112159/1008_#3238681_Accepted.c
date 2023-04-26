#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show1(int c,char s[100])
{
    unsigned char *p = (unsigned char *) (&s);

    while(c--)
        printf("%02x ",*p++);
    printf("\n");

    return;
}

void show2(int c,double s)
{
    unsigned char *p = (unsigned char *) (&s);

    while(c--)
        printf("%02x ",*p++);
    printf("\n");

    return;
}

int main()
{
    char s[100];int c;

    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.')==0)
        {
            c=sizeof((atoi(s)));
            show1(c,atoi(s));
        }
        else
        {
            c=sizeof((atof(s)));
            show2(c,(atof(s)));
        }

    }
}