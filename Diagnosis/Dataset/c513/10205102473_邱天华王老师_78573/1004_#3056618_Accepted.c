#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char s[31];
    int toint(int x);
    int todou(double y);
    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.')==0)toint(atoi(s));
        else todou(atof(s));
    }
    return 0;
}
int toint(int x)
{
    int m=sizeof(x);
    unsigned char *p=(unsigned char*)&x;
    while(m--)printf("%02x ",*p++);
    printf("\n");
    return 0;
}
int todou(double y)
{
    int m=sizeof(y);
    unsigned char* p=(unsigned char*)&y;
    while(m--)printf("%02x ",*p++);
    printf("\n");
    return 0;
}