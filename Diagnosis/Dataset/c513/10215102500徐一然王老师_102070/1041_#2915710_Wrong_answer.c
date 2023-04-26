#include <stdio.h>
#include<string.h>

int main()
{
    char s[51];
    int len=0,max=0;
    scanf("%s",s);
    char*p=s;
    while(*p)
    {
        if(*p=='|')
        {
            len++;
            p++;
            if(*p=='|')
            {
                if(max<len)
                {
                    max=len;
                }
                len=0;
                p++;
            }
            else
            {
                len++;
                p++;
            }
        }
        else
        {
            p++;
            if(*p=='|')
            {
                if(max<len)
                {
                    max=len;
                }
                len=0;
                p++;
            }
            else
            {
                len++;
                p++;
            }
        }
    }
    printf("%d",max);
}
