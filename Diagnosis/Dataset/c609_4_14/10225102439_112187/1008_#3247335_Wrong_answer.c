#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void solve_int(int n)
{
    int size=sizeof(n);
    unsigned char* p=(unsigned char*)&n;
    while (size--)
        printf("%02x",*p++);
    printf("\n");
}

void solve_double(double d)
{
    int size=sizeof(d);
    unsigned char* p=(unsigned char*)&d;
    while (size--)
        printf("%02x",*p++);
    printf("\n");
}

int main()
{
    char s[50];
    while (scanf("%s\n",&s)!=-1)
    {
        if ((strchr(s,'.'))==0) solve_int(atoi(s));
        else solve_double(atof(s));
    }
    return 0;
}
