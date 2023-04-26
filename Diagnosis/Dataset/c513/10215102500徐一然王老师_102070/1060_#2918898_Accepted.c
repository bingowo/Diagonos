#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char S[101];
    gets(S);
    char *p1=S;
    int len=0,max=0;
    int slen;
    slen=strlen(S);
    while(p1-S<slen)
    {
        if(isalpha(*p1))
        {
            p1++;
        }
        else
        {
            while(*p1=='0')
            {
                p1++;
            }
            while(isdigit(*p1))
            {
                len++;
                p1++;
            }
            if(max<len)
            {
                max=len;
            }
            len=0;

        }
    }
    printf("%d",max);
}
