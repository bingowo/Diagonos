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
            if(*(p+1)=='-')
            {
                len++;
                p=p+2;
                if(len>max)
                {
                    max=len;
                }
            }
            else
            {
                if(len>max)
                {
                    max=len;
                }
                len=0;
                p++;
            }
        }
        else
        {
            len=1;
            while(*p=='-')
            {
                p++;
            }
        }
    }
    if(len>max)
                {
                    max=len;
                }
    printf("%d",max);
}
