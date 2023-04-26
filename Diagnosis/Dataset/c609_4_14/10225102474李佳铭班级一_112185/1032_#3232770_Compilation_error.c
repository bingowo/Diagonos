#include <stdio.h>
#include<string.h>
#include <stdlib.h>

int main()
{
    char s[10000];
    scanf("%s",s);
    int max = 1;
    int sum = 1;
    for(int i = 0; i < strlen(s) - 1;i++)
    {
        if(s[i] != s[i++])
        {
            sum++;
        }
        else
        {
            max = (max > sum )? max : sum;
            sum = 1;
        }
    }
    printf("%d",max);
