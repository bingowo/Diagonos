#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int m,int n)
{
    return (n?GCD(n,m%n):m);
}

int main()
{
    int n,gcd;
    char s[130];
    scanf("%d",&n);
    gets(s);
    for(int i=0;i<n;i++)
    {
        gets(s);
        int a=0;
        for(int j=0;j<strlen(s);j++)
        {
            int d=1;
            for(int m=0;m<8;m++)
            {
                if(((unsigned char)s[j])&d) a++;
                d=d<<1;
            }

        }
        gcd=GCD(a,8*strlen(s));
        printf("%d/%d\n",a/gcd,8*strlen(s)/gcd);
    }
    return 0;
}