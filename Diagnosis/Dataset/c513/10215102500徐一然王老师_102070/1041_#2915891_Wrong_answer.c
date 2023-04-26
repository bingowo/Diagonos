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
                len=1;
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
            len++;
            while(*p=='-')
                p++;
        }
    }
    printf("%d",max);
}
