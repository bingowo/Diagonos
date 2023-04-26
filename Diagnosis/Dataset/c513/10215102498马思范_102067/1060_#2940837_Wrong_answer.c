#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char s[101];
    scanf("%s",s);
    int len= strlen(s);
    int max=0;
    int num=0;
    char *p=s;
    while (p-s<len)
    {
        if(isalpha(*p))
        {
            p++;
        }
        else
        {
            while (*p=='0')
            {
                p++;
            }
            while (isdigit(*p))
            {
                num++;
                p++;
            }
            if(max<num)
            {
                max=num;
            }
            len=0;
        }
    }
    printf("%d",max);
}