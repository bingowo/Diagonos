#include <stdio.h>
#include <stdlib.h>

int main()
{
    char m[2],f[2],b[2];
    scanf("%s %s %s",f,m,b);
    if(b[0]=='?')
    {
        if(f[0]=='A'&&m[0]=='A')
        {
            printf("%s %s %s",f,m,"{A,O}");
        }
        else if(f[0]=='B'&&m[0]=='B')
        {
            printf("%s %s %s",f,m,"{B,O}");
        }
        else if(f[0]=='O')
            printf("%s %s %s",f,m,m);
        else if(m[0]=='O')
            printf("%s %s %s",f,m,f);
        else
        {
            printf("%s %s %s",f,m,"{A,B,AB,O}");
        }
    }

    return 0;
}
