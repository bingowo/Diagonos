#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[101];
    char s2[205];
    scanf("%s",s1);
    int i;
    int x = 0;
    int j = 0;
    for(i = 0;i < strlen(s1);i++)
    {
        if(s1[i] <= s1[i + 1])
        {
            s2[x++] = s1[i];
            s2[x++] = s1[i];
        }
        else
        {
            s2[x++] = s1[i];
        }


    }
    s2[x] = '\0';
    printf("%s",s2);
    return 0;
}
