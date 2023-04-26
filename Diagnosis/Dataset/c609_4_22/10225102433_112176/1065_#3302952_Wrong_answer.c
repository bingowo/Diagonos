#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int a;
    char *s;
}test;

int main()
{
    char s[10];
    s[0] = '\0';
    printf("%u",strlen(s));
//    printf("%d %d",'0','A');
}