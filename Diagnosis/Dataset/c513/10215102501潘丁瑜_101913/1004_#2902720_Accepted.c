#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void print_int(int n);
void print_double(double n);
int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.')==0) print_int(atoi(s));
        else print_double(atof(s));
        printf("\n");
    }
    return 0;
}
void print_int(int n)
{
    int byte = sizeof(n);
    unsigned char *p = (unsigned char *)&n;
    while(byte--)
    {
        printf("%02x ",*p++);
    }
}

void print_double(double n)
{
    int byte = sizeof(n);
    unsigned char *p = (unsigned char *)&n;
    while(byte--)
    {
        printf("%02x ",*p++);
    }
}

