#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* s = (char*)malloc(55*sizeof(char));
    memset(s, 0, 55*sizeof(char));
    scanf("%s", s);
    int i, slen;
    int len = 1, max = 1;
    slen = strlen(s);
    for(i=0; i<slen; i++)
    {
        if(i == slen-1)
        {
            if(len > max)
                max = len;
            break;
        }
        if(s[i] != s[i+1])
            len++;
        else
        {
            if(len > max)
                max = len;
            len = 1;
        }
    }
    printf("%d", max);

    return 0;
}
