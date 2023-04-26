#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a,int b)
{
    return a?gcd(b%a,a):b;
}

int main()
{
    int p=0,n;
    char s[120];
    scanf("%d\n",&n);
    for(int k=0;k<n;k++)
    {
        gets(s);
        int cnt=0;
        for(int i=0;i<sizeof(s);i++)
        {
            int d=1;
            p=p+8;
            for(int j=0;j<8;j++)
            {
                if(d&s[i])cnt++;
                d=d<<1;
            }
        }
        int g=gcd(cnt,p);
        printf("%d/%d\n",cnt/g,p/g);
    }
    return 0;
}
