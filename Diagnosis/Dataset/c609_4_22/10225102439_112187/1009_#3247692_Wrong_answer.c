#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(a,b)
{
    if (b==0) return a;
    else return gcd(b,a%b);
}

int main()
{
    int n=0,T;
    scanf("%d\n",&T);
    for (;n<T;n++)
    {
        char s[121];
        scanf("%s\n",&s);
        int len=strlen(s),cnt=0,x=0;
        for (int i=0;i<len;i++)
        {
                if (s[i]>127) cnt++;
                int a=s[i];
                while (a)
                {
                    a&=(a-1);
                    x++;
                }
        }
        int y=(len+cnt)*8,m=gcd(y,x);
        y=y/m;
        x=x/m;
        printf("%d/%d\n",x,y);
    }
    return 0;
}