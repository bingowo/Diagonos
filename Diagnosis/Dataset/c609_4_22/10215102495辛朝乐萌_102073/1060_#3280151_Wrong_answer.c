#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int exchange(char s[])
{
    int len= strlen(s);
    int res=0;
    for (int i = 0; i < len-1; ++i) {
        if ('s[i]'<='s[i+1]') res++;
        else break;
    }
    return res;
}

int main(void)
{
    char s[10000];
    scanf("%s",s);
    int res= exchange(s);
    for (int i = 0; i < res; ++i) {
        printf("%c%c",s[i],s[i]);
    }
    for (int i = res; i < strlen(s); ++i) {
        printf("%c",s[i]);
    }
    return 0;
}