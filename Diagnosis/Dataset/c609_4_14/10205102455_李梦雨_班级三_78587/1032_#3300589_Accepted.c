#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[51];
    scanf("%s",s);
    int Max=1;
    int x=1;
    for(int i=0;i<strlen(s)-1;i++)
    {
        if(s[i]==s[i+1])
        {
            if(Max<x) Max=x;
            x=1;
        }
        else
        {
            x++;
        }
    }
    if(Max<x) Max=x;
    printf("%d\n",Max);
    return 0;
}