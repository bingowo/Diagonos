#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[101];
    char s2[205];
    scanf("%s",s1);
    int i;
    for(i = 0;i < strlen(s1);i++)
    {
        if(s1[i] > s1[i + 1])
            break;
    }
    int x = 0;
    int j = 0;
    for(j = 0; j < i ; j++)
    {
        s2[x++] = s1[j];
        s2[x++] = s1[j];
    }
    for(;j < strlen(s1);j++)
    {
        s2[x++] = s1[j];
    }
    s2[x] = '\0';
    printf("%s",s2);
    return 0;
}
