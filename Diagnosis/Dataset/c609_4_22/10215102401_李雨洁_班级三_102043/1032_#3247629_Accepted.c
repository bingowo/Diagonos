#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char s[51];
    scanf("%s", s);
    int len = strlen(s);
    int max=1;
    int end = 1;
    for (int i = 0; i < len-1; i++)
    {
        if (s[i] != s[i + 1])
        {
            max++;
            if (max > end)end = max;
        }
        else
            max = 1;
    }
    printf("%d\n", end);
    return 0;
}