#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a,int b)
{
    int t;
    while(t!=0)
    {
        t=a%b;
        a=b;
        b=t;
    }
   return b;
}

int main()
{
    int n; scanf("%d\n",&n);

    for(int i=0;i<n;i++)
    {
        char s[128]; gets(s);
        int cnt=0,len=strlen(s);

        for(int j=0;j<len;j++)
        {
            unsigned char c=s[j];
            for(int k=0;k<8;k++)
            {
                cnt+=c%2;
                c>>=1;
            }
        }

        int g=gcd(len*8,cnt);

        printf("%d/%d\n",cnt/g,len*8/g);
    }

    return 0;
}