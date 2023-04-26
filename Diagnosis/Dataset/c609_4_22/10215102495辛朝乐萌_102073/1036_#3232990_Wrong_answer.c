#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[10000];
    int num=0;
    scanf("%s",s);
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i]=='(') num++;
    }
    printf("%d",num);
    return 0;
}