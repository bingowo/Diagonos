#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void int_s(int n);
void double_s(double d);

int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.')!=NULL) double_s(atof(s));
        else int_s(atoi(s));
    }
}
void int_s(int n)
{
    int len=sizeof(n);
    unsigned char* p=&n;
    char c;
    while(len--)
    {
        c=len==0?'\n':' ';
        printf("%.2x%c",*p,c);
        p++;
    }
}
void double_s(double d)
{
    int len=sizeof(d);
    unsigned char* p=&d;
    char c;
    while(len--)
    {
        c=len==0?'\n':' ';
        printf("%.2x%c",*p,c);
        p++;
    }
}
