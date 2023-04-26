#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
    char c,d;int f1=0,f2=0,s1=0,s2=0;
    while((c=getchar())!=EOF)
    {
        if(c=='"'&& f1==0)
        {
            f1=1;putchar(c);
        }
        else if(c=='"' &&f1==1)
        {
            f1=0;putchar(c);
        }
        else if(c=='\''&& f2==0)
        {
            f2=1;putchar(c);
        }
        else if(c=='\'' && f2==1)
        {
            f2=0;putchar(c);
        }
        else if(c=='/' && f1==0 && f2==0)
        {
            d=getchar();
            if(d=='/')
            {
                s1=1;putchar(' ');putchar(' ');
            }
            else if(d=='*' && s2==0)
            {
                s2=1;
            }
            else
            {
                putchar(c);putchar(d);
            }
        }
        else if(c=='*' && f1==0 && f2==0)
        {
            d=getchar();
            if(d=='/' && s2==1)
            {
                s2=0;
            }
            else
            {
                putchar(c);putchar(d);
            }
        }
        else
        {
            if(c=='\n') s1=0;
            if(s1==1) putchar(' ');
            else if(s2!=1) putchar(c);
        }

    }
    return 0;
}
