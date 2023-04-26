#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
    char s[80] = {};
    gets(s);
    long long a=0,b=0,c=1;
    int i = 0;
    while (s[i]!='.'&&s[i])
    {
        int z = (s[i]=='2')?-1:s[i]-'0';
        a = a*3+z;
        i++;
    }
    if (strchr(s,'.'))
    {
        i = strlen(s)-1;
        while (s[i]!='.')
        {
            int z = (s[i]=='2')?-1:s[i]-'0';
            b += z*c;
            c *= 3;
            i--;
        }
        if (a==0) printf("%lld %lld",b,c);
        else if (a>0&&b>=0) printf("%lld %lld %lld",a,b,c);
        else if (a<0&&b<0) printf("%lld %lld %lld",a-1,-b,c);
        else if (a>0&&b<0) printf("%lld %lld %lld",a-1,c+b,c);
        else printf("%lld %lld %lld",a+1,c-b,c);
    }
    else printf("%lld",a);
    system("pause");
    return 0;
}