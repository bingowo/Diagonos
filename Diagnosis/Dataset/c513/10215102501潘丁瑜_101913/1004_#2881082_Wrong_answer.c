#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_int(int n);
void print_double(double n);
int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.')==0) print_int(atoi(s));
        else print_double(atof(s));
    }
    return 0;
}
void print_int(int n)
{
    int byte = sizeof(n);
    char* p = (char* ) &n;
    while(byte--)
    {
        printf("%02x ",*p++);
    }
    printf("\n");
}
void print_double(double n)
{
    int byte = sizeof(n);
    char* p = (char* ) &n;
    while(byte--)
    {
        printf("%02x ",*p++);
    }
    printf("\n");
}