#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int idn(long long x)
{
    int a;
    while (x)
    {
       a=x%10;
       x=x/10;
        if (a==9)
            return 1;
    }
    return 0;
}

int main()
{
    char s[110]={0};
    scanf("%s",s);
    if (strlen(s)<18)
    {
        long long x=atoll(s);
        if (strchr(s,'9') || x%9==0)
            while (idn(x) || x%9==0)
                x++;
        else
        {
            x++;
            while (idn(x) || x%9==0)
                x++;
        }
        printf("%lld\n",x);

    }



    return 0;
}
