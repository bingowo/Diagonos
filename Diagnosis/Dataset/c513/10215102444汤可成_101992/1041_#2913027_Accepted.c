#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num = 1;
    int max = 1;
    char s[51] = {0};
    scanf("%s", s);
    int len = strlen(s);
    int i = 0;
    for(i = 0; i<len-1; i++)
    {
        if(s[i]!=s[i+1])
        {
            num++;
            if(num>max) max = num;
        }
        else
        {
            num = 1;
        }
    }
    printf("%d", max);
    return 0;
}
