#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void test(char s[])
{
    int len= strlen(s);
    if (len%2) printf("N0\n");
    int res;
    for (int i = 0; i < len; ++i) {
        if (s[i]==s[len-i-1]) res++;
        else continue;
    }
    if (res==len/2) printf("Yes\n");
    else printf("N0\n");
}

int main(void)
{
    int t;
    scanf("%d",&t);
    char s[101];
    for (int i = 0; i < t ; ++i) {
        scanf("%s",s);
        test(s);
    }
    return 0;
}