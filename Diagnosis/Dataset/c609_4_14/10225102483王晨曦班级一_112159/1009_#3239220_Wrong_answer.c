#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a,int b)
{
    int c;
    c = (a>b)?b:a;
    while((a%c != 0) || (b%c != 0))
        c--;
   return c;
}

int main()
{
    int n; scanf("%d\n",&n);

    for(int i=0;i<n;i++)
    {
        char s[1280]; gets(s);
        int cnt=0,len=strlen(s);

        for(int j=0;j<len;j++)
        {
            unsigned char c=s[j];
            for(int k=0;k<16;k++)
            {
                cnt+=c%2;
                c>>=1;
            }
        }

        int g=gcd(len*8,cnt);
        printf("%d\n",g);
        printf("%d/%d\n",cnt/g,len*8/g);
    }

    return 0;
}