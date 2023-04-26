#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,n=0,m=0,len;
    char s[100];
    gets(s);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]<='9'&&s[i]>='1')
            n++;
        else
        {
            if(n>m)
                m=n;
            n=0;
        }
    }
    printf("%d",m);
    return 0;
}
