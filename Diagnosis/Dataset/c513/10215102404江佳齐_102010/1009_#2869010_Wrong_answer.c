#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int m,int n)
{
    return (n?GCD(n,m%n):m);
}
int main()
{
    int n,a=0,d=1,gcd;
    char s[121];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        for(int j=0;j<strlen(s);j++)
        {
            for(int m=0;m<8;m++)
            {
                if(s[j]&d) a++;
                d=d<<1;
            }

        }
        gcd=GCD(a,8*strlen(s));
        printf("%d/%d\n",a/gcd,8*strlen(s)/gcd);
    }
    return 0;
}