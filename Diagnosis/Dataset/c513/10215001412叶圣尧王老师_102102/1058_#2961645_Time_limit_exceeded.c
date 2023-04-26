#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char s[100];
    while(gets(s)!=EOF)
    {puts(s);putchar('\n');gets(s);}
}